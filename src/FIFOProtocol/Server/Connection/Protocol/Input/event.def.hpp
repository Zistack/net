template <typename Request, typename Response, typename Interface>
template <typename InputStream>
void
T <Request, Response, Interface>::event
(
	InputStream && input_stream,
	Thread::Nursery::T & nursery
)
{
	Request request = this -> interface . readRequest
	(
		std::forward <InputStream> (input_stream)
	);

	Thread::Delay::T <Response> response_delay;

	output.push (response_delay);

	nursery.add
	(
		[
			this,
			request (std::move (request)),
			response_delay (std::move (response_delay))
		] ()
		{
			this->respond (request, response_delay);
		}
	);
}
