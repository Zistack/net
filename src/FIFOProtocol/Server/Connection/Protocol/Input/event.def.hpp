template <typename Interface, typename Request, typename Response>
template <typename InputStream>
void
T <Interface, Request, Response>::event
(
	InputStream && input_stream,
	Thread::Nursery::Collection::T <true> & nursery
)
{
	Request request = this -> interface () . readRequest
	(
		std::forward <InputStream> (input_stream)
	);

	Thread::Delay::T <Response> response_delay;

	this -> interface () . pushOutput (response_delay);

	nursery . add
	(
		[
			this,
			request (std::move (request)),
			response_delay (std::move (response_delay))
		] ()
		{
			this -> respond (request, response_delay);
		}
	);
}
