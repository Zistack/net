struct T
{
	T (IO::Interface::InputStream::T & input_stream, IO::CancelSignal::T & input_cancel_signal, Failure::CancelScope::T & cancel_scope);

	T (uint64_t,
	    const URI::T & uri,
	    const std::string & version,
	    const HeaderMap::T & headers,
	    std::unique_ptr <Entity::T> && entity);

	void
	writeTo (const NullableString::T & transfer_encoding_spec, IO::Interface::OutputStream::T & output_stream, IO::CancelSignal::T & output_cancel_signal, Failure::CancelScope::T & cancel_scope);

	~T () = default;

	private:
	void
	getStatusLine (IO::Interface::InputStream::T & input_stream);

	uint64_t status_code;
	URI::T uri;
	std::string version;

	HeaderMap::T headers;

	std::unique_ptr <Entity::T> entity;
};
