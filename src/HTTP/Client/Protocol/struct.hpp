struct T : FIFOProtocol::Client::Protocol::T<Request::T, Response::T>
{
	T (const Config::T & config);

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

	TransferEncoding::Encoder::Config::T transfer_encoding_config;
};
