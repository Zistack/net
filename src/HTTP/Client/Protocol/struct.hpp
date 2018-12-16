struct T : FIFOProtocol::Client::Protocol::T<Request::T, Response::T>
{
	T (std::chrono::milliseconds io_timeout,
	    std::chrono::milliseconds round_trip_timeout);

	~T () override = default;

	private:
	void
	writeRequest (const Request::T & request,
	    IO::Blocking::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_cancel_signal,
	    Failure::CancelScope::T & output_cancel_scope) override;

	Response::T
	readResponse (IO::Blocking::InputStream::T & input_stream,
	    IO::CancelSignal::T & input_cancel_signal,
	    Failure::CancelScope::T & input_cancel_scope) override;
};
