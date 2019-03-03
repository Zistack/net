void
T::run (IO::Interface::NonblockingInputStream::T & input_stream,
    IO::Interface::NonblockingOutputStream::T & output_stream)
{
	Failure::ExceptionStore::T exception_store;

	{
		Thread::Nursery::T nursery (exception_store);

		nursery.add (this->input, &Input::T::run, &this->input, input_stream);

		nursery.run (
		    this->output, &Output::T::run, &this->output, output_stream);
	}

	exception_store.poll ();
}
