template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::computeResponse (RequestType request,
    ::Protocol::Delay::T<ResponseType> delay)
{
	ResponseType response;

	try
	{
		response = this->map (request);
	}
	catch (...)
	{
		this->destroyRequest (request);
		throw;
	}

	delay.set (response);
	this->destroyRequest (request);
}
