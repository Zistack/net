template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::init (
    Interface::NonblockingInputStream::T * input_stream,
    Interface::NonblockingOutputStream::T * output_stream,
    Failure::ExceptionStore::T & exception_store,
    std::function<void(void)> stop)
{
	this->input_timeout_signal = new Signal::T ();
	this->input_stream =
	    new Blocking::InputStream::T (input_stream, input_timeout_signal);

	this->output_timeout_signal = new Signal::T ();
	this->output_stream =
	    new Blocking::OutputStream::T (output_stream, output_timeout_signal);

	this->stop = stop;

	this->nursery =
	    new Thread::Nursery::T (exception_store, [&]() { this->stop (); });
	this->nursery->add (&T::run, this);
}
