template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::cancel ()
{
	this->shutdown_signal.cancel ();
}
