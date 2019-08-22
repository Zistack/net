template
<
	typename Protocol,
	typename Request,
	typename Response,
	typename Details
>
void
T <Protocol, Request, Response, Details>::respond
(
	const Request & request,
	Thread::Delay::T <Response> response_delay
)
{
	try
	{
		response_delay . set (std::move (this -> details () . map (request)));
	}
	catch (...)
	{
		response_delay . cancel ();
		throw;
	}
}
