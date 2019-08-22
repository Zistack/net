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
		Failure::ExceptionStore::T exception_store;
		Thread::Nursery::T nursery (exception_store);

		Scope::T recode_cancel_scope (recode_cancel_slot, nursery);

		// Iterators so that we can deal with the first and last stages in a 
		// special way.
		auto next_it = this -> m_stages . begin ();
		auto current_it = next_it;
		++ next_it;

		// Do first stage.

		IO::Pipe::T first_pipe;
		IO::Blocking::InputStream::T next_input_stream
		(
			first_pipe . reciever ()
		);

		StageExecutor::T first_stage
		(
			std::forward <InputStream> (input_stream),
			* current_it,
			IO::Blocking::OutputStream::T (first_pipe . sender ()),
			std::move (first_pipe)
		);

		nursery . add
		(
			first_stage,
			& decltype (first_stage)::run,
			& first_stage
		);

		// Do bulk stages

		current_it = next_it;
		next_it ++;

		using InnerStageExecutor = decltype
		(
			StageExecutor::T
			(
				IO::Blocking::InputStream::T
				(
					std::declval <IO::Pipe::T> () . reciever ()
				),
				std::declval <Stage> (),
				IO::Blocking::OutputStream::T
				(
					std::declval <IO::Pipe::T> () . reciever ()
				),
				std::move (std::declval <IO::Pipe::T> ())
			)
		);

		std::list <InnerStageExecutor> inner_stages;
		IO::Blocking::InputStream::T current_input_stream
		(
			std::move (next_input_stream)
		);

		while (next_it != this -> m_stages . end ())
		{
			IO::Pipe::T pipe_to_next;
			next_input_stream = IO::Blocking::InputStream::T
			(
				first_pipe . reciever ()
			);

			inner_stages . emplace_back
			(
				std::move (current_input_stream),
				* current_it,
				IO::Blocking::OutputStream::T (pipe_to_next . sender ()),
				std::move (pipe_to_next)
			);

			nursery . add
			(
				inner_stages . back (),
				& InnerStageExecutor::run,
				& inner_stages . back ()
			);

			current_input_stream = std::move (next_input_stream);

			current_it = next_it;
			next_it ++;
		}

		// Do last stage

		StageExecutor::T last_stage
		(
			std::move (current_input_stream),
			* current_it,
			std::forward <OutputStream> (output_stream)
		);

		nursery . run (last_stage, & decltype (last_stage)::run, & last_stage);
	}
}
