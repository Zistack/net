template <typename Response, typename Interface>
template <typename InputStream>
void
T<Response, Interface>::event (InputStream && input_stream)
{
	Thread::Delay::T<Response> response_delay = this->response_queue.pop ();

	response_delay.value ().set (std::move (this->interface.readResponse (
	    std::forward<InputStream> (input_stream))));
}
