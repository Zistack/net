template <typename Request, typename Response, typename Interface>
void
T<Request, Response, Interface>::respond (const Request & request,
    Thread::Delay::T<Response> response_delay)
{
	try
	{
		response_delay.set (std::move (this->interface.map (request)));
	}
	catch (...)
	{
		response_delay.cancel ();
		throw;
	}
}
