struct T : FIFOProtocol::Client::Protocol::T<Request::T, Response::T>
{
	T (const Config::Value::T & config);

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

	TransferEncoding::Encoder::Config::Value::T transfer_encoding_config;
	uint64_t temp_file_threshhold;
};
