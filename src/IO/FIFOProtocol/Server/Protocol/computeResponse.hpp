template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::computeResponse (
    T<RequestType, ResponseType> * protocol,
    RequestType request,
    std::promise<ResponseType> * promise)
{
	ResponseType response;

	try
	{
		response = protocol->map (request);
	}
	catch (...)
	{
		promise->set_exception (std::current_exception ());
		protocol->destroyRequest (request);
		throw;
	}

	promise->set_value (response);
	protocol->destroyRequest (request);
}
