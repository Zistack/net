template <typename RequestType, typename ResponseType>
void
T<RequestType, ResponseType>::run (
    IO::Interface::NonblockingInputStream::T & input_stream,
    IO::Interface::NonblockingOutputStream::T & output_stream)
{
	Failure::ExceptionStore::T exception_store;

	{
		Thread::Nursery::T nursery (exception_store);

		nursery.add (this->input,
		    &Input::T<RequestType, ResponseType>::run,
		    this->input,
		    *this,
		    input_stream);

		nursery.run (this->output,
		    &Output::T<RequestType, ResponseType>::run,
		    this->output,
		    *this,
		    output_stream);
	}

	exception_store.poll ();
}
