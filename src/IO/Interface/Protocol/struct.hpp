struct T : Failure::Cancellable::T
{
	virtual void
	prime (IO::Interface::NonblockingInputStream::T & input_stream,
	    IO::Interface::NonblockingOutputStream::T & output_stream) = 0;

	virtual void
	run () = 0;

	virtual void
	cancel () override = 0;

	virtual ~T () = default;
};
