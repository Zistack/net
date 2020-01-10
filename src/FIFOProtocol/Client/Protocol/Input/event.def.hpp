template <typename Interface, typename Response>
template <typename InputStream>
void
T <Interface, Response>::event (InputStream && input_stream)
{
	Thread::Delay::T <Response> response_delay;

	if constexpr
	(
		HooksLoadEvents::HasReadActive::T <Interface>::value &&
		HooksLoadEvents::HasQueueIdle::T <Interface>::value
	)
	{
		this -> interface () . readActive ();

		response_delay = this -> m_response_queue . pop
		(
			[&] () { this -> interface () . queueIdle (); }
		);
	}
	else
	{
		response_delay = this -> m_response_queue . pop ();
	}

	response_delay . set
	(
		std::move
		(
			this -> interface () . readResponse
			(
				std::forward <InputStream> (input_stream)
			)
		)
	);
}
