struct T : IO::Interface::Protocol::T
{
	T (IO::Interface::Protocol::T * initial_protocol);

	void
	run (IO::Interface::NonblockingInputStream::T * input_stream,
	    IO::Interface::NonblockingOutputStream::T * output_stream) override;

	void
	stop () override;

	T () = default;

	std::shared_ptr<IO::Interface::Protocol::T> initial_protocol;
	std::shared_ptr<IO::Interface::Protocol::T> current_protocol;
};
