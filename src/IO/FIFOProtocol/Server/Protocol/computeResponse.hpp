template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::computeResponse (
    T<RequestType, ResponseType> * protocol,
    RequestType request,
    std::promise<ResponseType> * promise)
{
	ResponseType response = protocol->map (request);

	promise->set_value (response);

	protocol->destroyRequest (request);
}
