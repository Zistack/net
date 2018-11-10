template <class RequestType, class ResponseType>
std::unique_ptr<IO::Interface::Protocol::T>
T<RequestType, ResponseType>::make ()
{
	return std::make_unique<Protocol::T<RequestType, ResponseType>> (
	    this->input_timeout, this->output_timeout);
}
