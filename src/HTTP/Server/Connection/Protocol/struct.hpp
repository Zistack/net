struct T
    : FIFOProtocol::Server::Connection::Protocol::T<Request::T, Response::T>
{
	T (const Config::Value::T & config, Responder::T & responder);

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

	const TransferEncoding::Encoder::Config::Value::T transfer_encoding_config;
	uint64_t temp_file_threshhold;

	Responder::T & responder;
};
