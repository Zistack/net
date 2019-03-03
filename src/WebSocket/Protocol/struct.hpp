struct T : IO::Interface::Protocol::T
{
	T (const Config::Value::T & config, Dispatcher::T & dispatcher);

	void
	prime () override;

	void
	run (IO::Interface::NonblockingInputStream::T & input_stream,
	    IO::Interface::NonblockingOutputStream::T & output_stream) override;

	void
	cancel () override;

	void
	send (std::unique_ptr<Message::T> && message);

	void
	ping (const std::vector<uint8_t> & payload);

	void
	pong (const std::vector<uint8_t> & payload);

	~T () override = default;

	private:
	Input::T input;
	Output::T output;
};
