template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::computeResponse (RequestType request,
    ::Protocol::Delay::T<ResponseType> response_delay)
{
	ResponseType response;

	try
	{
		response = this->map (request);
	}
	catch (...)
	{
		response_delay.cancel ();
		throw;
	}

	response_delay.set (response);
}
