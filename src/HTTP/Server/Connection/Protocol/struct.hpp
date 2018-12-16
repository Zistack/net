struct T
    : FIFOProtocol::Server::Connection::Protocol::T<Request::T, Response::T>
{
	T (std::chrono::milliseconds input_timeout,
	    std::chrono::milliseconds output_timeout,
	    Responder::T & responder);

	~T () override = default;

	private:
	Request::T
	readRequest (IO::Blocking::InputStream::T & input_stream,
	    IO::CancelSignal::T & input_cancel_signal,
	    Failure::CancelScope::T & input_cancel_scope) override;

	Response::T
	map (const Request::T & request) override;

	void
	writeResponse (const Response::T & response,
	    IO::Blocking::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_cancel_signal,
	    Failure::CancelScope::T & output_cancel_scope) override;

	Responder::T & responder;
};
