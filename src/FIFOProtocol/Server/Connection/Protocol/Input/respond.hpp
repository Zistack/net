template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::respond (
    Protocol::T<RequestType, ResponseType> & protocol,
    const RequestType & request,
    ::Protocol::Delay::T<ResponseType> response_delay)
{
	ResponseType response;

	try
	{
		response = std::move (protocol.map (request));
	}
	catch (...)
	{
		response_delay.cancel ();
		throw;
	}

	response_delay.set (std::move (response));
}
