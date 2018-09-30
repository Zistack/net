template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::computeResponse (RequestType request,
    std::promise<ResponseType> * promise)
{
	ResponseType response;

	try
	{
		response = this->map (request);
	}
	catch (...)
	{
		promise->set_exception (std::current_exception ());
		this->destroyRequest (request);
		throw;
	}

	promise->set_value (response);
	this->destroyRequest (request);
}
