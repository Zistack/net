template <typename Interface, typename Request, typename Response>
void
T <Interface, Request, Response>::respond
(
	const Request & request,
	Thread::Delay::T <Response> response_delay
)
{
	try
	{
		response_delay . set (std::move (this -> interface () . map (request)));
	}
	catch (...)
	{
		response_delay . cancel ();
		throw;
	}
}
