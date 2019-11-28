template <typename Interface, typename Response>
template <typename InputStream>
void
T <Interface, Response>::event (InputStream && input_stream)
{
	Thread::Delay::T <Response> response_delay =
		this -> m_response_queue . pop ();

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
