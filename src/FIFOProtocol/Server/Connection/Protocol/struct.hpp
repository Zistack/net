template <typename RequestType, typename ResponseType>
struct T : IO::Interface::Protocol::T
{
	T (const Config::Value::T & config);

	void
	prime () override;

	void
	run (IO::Interface::NonblockingInputStream::T & input_stream,
	    IO::Interface::NonblockingOutputStream::T & output_stream) override;

	void
	cancel () override;

	virtual ~T () override = default;

	protected:
	virtual RequestType
	readRequest (IO::Blocking::InputStream::T & input_stream,
	    IO::CancelSignal::T & input_cancel_signal,
	    Failure::CancelScope::T & input_cancel_scope) = 0;

	virtual ResponseType
	map (const RequestType & request) = 0;

	virtual void
	writeResponse (const ResponseType & response,
	    IO::Blocking::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_cancel_signal,
	    Failure::CancelScope::T & output_cancel_scope) = 0;

	private:
	std::chrono::milliseconds input_timeout;
	std::chrono::milliseconds output_timeout;

	Input::T<RequestType, ResponseType> input;
	Output::T<RequestType, ResponseType> output;
};
