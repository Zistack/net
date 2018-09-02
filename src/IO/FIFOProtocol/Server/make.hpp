template <class RequestType, class ResponseType>
Protocol::T<RequestType, ResponseType> *
T<RequestType, ResponseType>::make ()
{
	return new Protocol::T<RequestType, ResponseType> (this->input_timeout,
	    this->output_timeout,
	    this->readRequest,
	    this->map,
	    this->writeResponse,
	    this->destroyRequest,
	    this->destroyResponse);
}
