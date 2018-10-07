template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::computeResponse (RequestType request,
    ::Protocol::Delay::T<ResponseType> delay)
{
	Failure::CleanupAction::T cleanup_request (
	    [this, &request]() { this->destroyRequest (request); });

	ResponseType response;

	response = this->map (request);

	delay.set (response);
}
