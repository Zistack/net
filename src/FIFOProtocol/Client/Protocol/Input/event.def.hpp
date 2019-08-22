template <typename Protocol, typename Response, typename Details>
template <typename InputStream>
void
T <Protocol, Response, Details>::event (InputStream && input_stream)
{
	Thread::Delay::T <Response> response_delay =
		this -> m_response_queue . pop ();

	response_delay . value () . set
	(
		std::move
		(
			this -> details () . readResponse
			(
				std::forward <InputStream> (input_stream)
			)
		)
	);
}
