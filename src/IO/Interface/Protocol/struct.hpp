struct T
{
	virtual void
	prime (IO::Interface::NonblockingInputStream::T & input_stream,
	    IO::Interface::NonblockingOutputStream::T & output_stream) = 0;

	virtual void
	run () = 0;

	virtual void
	stop () = 0;

	virtual ~T () = default;
};
