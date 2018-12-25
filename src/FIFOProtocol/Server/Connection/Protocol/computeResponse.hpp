template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::computeResponse (const RequestType & request,
    ::Protocol::Delay::T<ResponseType> response_delay)
{
	ResponseType response;

	try
	{
		response = std::move (this->map (request));
	}
	catch (...)
	{
		response_delay.cancel ();
		throw;
	}

	response_delay.set (std::move (response));
}
