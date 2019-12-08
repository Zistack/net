template <typename Stage>
template
<
	typename InputStream,
	typename OutputStream,
	typename CancellableSlot
>
void
T <Stage>::recode
(
	InputStream && input_stream,
	OutputStream && output_stream,
	CancellableSlot & recode_cancel_slot
) const
{
	if (this -> m_stages . size () == 1)
	{
		StageExecutor::T stage
		(
			std::forward <InputStream> (input_stream),
			this -> m_stages . front (),
			std::forward <OutputStream> (output_stream)
		);

		Scope::T recode_cancel_scope (recode_cancel_slot, stage);

		stage . run ();
	}
	else
	{
		std::list <IO::Pipe::T> pipes (this -> m_stages . size () - 1);

		auto stage_iterator = this -> m_stages . begin ();
		auto next_pipe_iterator = pipes . begin ();

		StageExecutor::T first_stage
		(
			std::forward <InputStream> (input_stream),
			* stage_iterator,
			IO::Blocking::OutputStream::T (next_pipe_iterator -> sender ())
		);

		++ stage_iterator;
		auto last_pipe_iterator = next_pipe_iterator ++;

		std::list <InnerStageExecutor::T <Stage>> inner_stages;
		for
		(
			;
			next_pipe_iterator != pipes . end ();
			++ stage_iterator, last_pipe_iterator = next_pipe_iterator ++
		)
		{
			inner_stages . emplace_back
			(
				IO::Blocking::InputStream::T (last_pipe_iterator -> reciever ()),
				* stage_iterator,
				IO::Blocking::OutputStream::T (next_pipe_iterator -> sender ())
			);
		}

		StageExecutor::T last_stage
		(
			IO::Blocking::InputStream::T (last_pipe_iterator -> reciever ()),
			* stage_iterator,
			std::forward <OutputStream> (output_stream)
		);

		InnerCancellableSlot::T <Stage> inner_cancel_slot;

		Thread::Nursery::Aggregate::T nursery
		(
			std::forward_as_tuple
			(
				first_stage,
				[&] ()
				{
					first_stage . run ();
					pipes . front () . shutdown ();
				}
			),
			std::forward_as_tuple
			(
				inner_cancel_slot,
				[&] ()
				{
					InnerNursery::T <Stage> inner_nursery;

					Scope::T inner_cancel_scope
					(
						inner_cancel_slot,
						inner_nursery
					);

					auto executor_iterator = inner_stages . begin ();
					auto next_pipe_iterator = ++ pipes . begin ();

					for
					(
						;
						executor_iterator != inner_stages . end ();
						++ executor_iterator, ++ next_pipe_iterator
					)
					{
						inner_nursery . add
						(
							* executor_iterator,
							[&] ()
							{
								executor_iterator -> run ();
								next_pipe_iterator -> shutdown ();
							}
						);
					}
				}
			),
			std::forward_as_tuple
			(
				last_stage,
				[&] ()
				{ last_stage . run (); }
			)
		);

		Scope::T recode_cancel_scope (recode_cancel_slot, nursery);
	}
}
