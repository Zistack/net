template <class RequestType, class ResponseType>
void
T<RequestType, ResponseType>::init (
    Interface::NonblockingInputStream::T * input_stream,
    Interface::NonblockingOutputStream::T * output_stream)
{
	this->input_timeout_signal = new Signal::T ();
	this->input_stream =
	    new Blocking::InputStream::T (input_stream, this->input_timeout_signal);

	this->output_timeout_signal = new Signal::T ();
	this->output_stream = new Blocking::OutputStream::T (
	    output_stream, this->output_timeout_signal);
}
