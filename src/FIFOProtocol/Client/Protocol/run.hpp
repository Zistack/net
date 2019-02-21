template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::run (
    IO::Interface::NonblockingInputStream::T & input_stream,
    IO::Interface::NonblockingOutputStream::T & output_stream)
{
	{
		Thread::Nursery::T nursery;

		nursery.add (this->input,
		    &Input::T<ResponseType>::run,
		    &this->input,
		    input_stream);

		nursery.run (this->output,
		    &Output::T<RequestType>::run,
		    &this->output,
		    output_stream);
	}
}
