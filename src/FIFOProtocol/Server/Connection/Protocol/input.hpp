template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::input (
    IO::Blocking::InputStream::T & input_stream,
    Thread::Nursery::T & nursery)
{
	::Protocol::eventLoop (this->exception_store,
	    input_stream,
	    this->shutdown_signal,
	    &T::event,
	    this,
	    input_stream,
	    nursery);

	this->exception_store.poll ();
}
