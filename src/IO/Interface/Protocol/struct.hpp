struct T
{
	virtual void
	init (IO::Interface::NonblockingInputStream::T * input_stream,
	    IO::Interface::NonblockingOutputStream::T * output_stream,
	    Failure::ExceptionStore::T & exception_store,
	    std::function<void(void)> stop) = 0;

	virtual void
	event () = 0;

	virtual void
	clean () = 0;

	virtual ~T () = default;
};
