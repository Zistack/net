template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::run (
    IO::Interface::NonblockingInputStream::T & input_stream,
    IO::Interface::NonblockingOutputStream::T & output_stream)
{
	{
		Thread::Nursery::T nursery;

		nursery.add (this->input,
		    &Input::T<RequestType, ResponseType>::run,
		    &this->input,
		    *this,
		    input_stream);

		nursery.run (this->output,
		    &Output::T<RequestType, ResponseType>::run,
		    &this->output,
		    *this,
		    output_stream);
	}
}
