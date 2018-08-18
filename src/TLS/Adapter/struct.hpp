struct T
{
	T (SSL::T & ssl,
	    IO::Interface::Protocol::T & protocol,
	    uint64_t timeout_ns);

	void
	event ();

	void
	runProtocol ();

	void
	runOutputDump ();

	void
	clean ();

	~T ();

	static const int BUF_SIZE = 1024;

	SSL::T & ssl;
	IO::Interface::Protocol::T & protocol;
	uint64_t timeout_ns;

	IO::Pipe::T * socket_to_protocol;
	IO::Blocking::OutputStream::T * protocol_output_stream;
	char input_buffer[BUF_SIZE];
	IO::Signal::T * input_timeout_signal;

	IO::Pipe::T * protocol_to_socket;
	char output_buffer[BUF_SIZE];
	IO::Signal::T * output_timeout_signal;

	IO::Signal::T * shutdown_signal;

	Failure::ExceptionStore::T exception_store;
	Thread::Nursery::T nursery;
};
