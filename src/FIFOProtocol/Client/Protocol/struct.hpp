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

	ResponseType
	makeRequest (const RequestType & request);

	virtual ~T () override = default;

	protected:
	virtual void
	writeRequest (const RequestType & request,
	    IO::Blocking::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_cancel_signal,
	    Failure::CancelScope::T & output_cancel_scope) = 0;

	virtual ResponseType
	readResponse (IO::Blocking::InputStream::T & input_stream,
	    IO::CancelSignal::T & input_cancel_signal,
	    Failure::CancelScope::T & output_cancel_scope) = 0;

	private:
	// Given members

	std::chrono::milliseconds round_trip_timeout;

	// Internal members

	std::mutex mutex;

	Input::T<RequestType, ResponseType> input;
	Output::T<RequestType, ResponseType> output;
};
