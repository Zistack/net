template
<
	typename Protocol,
	typename Request,
	typename Response,
	typename Details
>
template <typename InputStream>
void
T <Protocol, Request, Response, Details>::event
(
	InputStream && input_stream,
	Thread::Nursery::Collection::T <true> & nursery
)
{
	Request request = this -> details () . readRequest
	(
		std::forward <InputStream> (input_stream)
	);

	Thread::Delay::T <Response> response_delay;

	this -> output () . push (response_delay);

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
