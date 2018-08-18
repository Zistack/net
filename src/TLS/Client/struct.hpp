struct T : IO::Interface::Protocol::T
{
	T (IO::Interface::Protocol::T & protcol,
	    Context::T & context,
	    uint64_t timeout_ns);

	void
	init (IO::Interface::NonblockingInputStream::T & input_stream,
	    IO::Interface::NonblockingOutputStream::T & output_stream) override;

	void
	event () override;

	void
	clean () override;

	~T () = default;

	IO::Interface::Protocol::T & protocol;
	Context::T & context;
	uint64_t timeout_ns;

	SSL::T * ssl;
	Adapter::T * adapter;
};
