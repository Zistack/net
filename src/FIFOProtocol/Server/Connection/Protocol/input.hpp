template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::input (
    IO::Blocking::InputStream::T & input_stream,
    Thread::Nursery::T & nursery)
{
	::Protocol::eventLoop (this->exception_store,
	    input_stream,
	    this->shutdown_signal,
	    [this, &input_stream, &nursery]() {
		    try
		    {
			    this->event (input_stream, nursery);
		    }
		    catch (IO::EOF::T)
		    {
			    throw;
		    }
	    });

	this->exception_store.poll ();
}
