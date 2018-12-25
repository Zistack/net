struct T
{
	T () = default;

	T (IO::Interface::InputStream::T & input_stream,
	    IO::CancelSignal::T & input_cancel_signal,
	    Failure::CancelScope::T & cancel_scope);

	T (const std::string & version,
	    uint64_t status_code,
	    const std::string & reason_phrase,
	    const HeaderMap::T & headers,
	    std::unique_ptr<Entity::T> && entity);

	void
	writeTo (const NullableString::T & transfer_encoding_spec,
	    IO::Interface::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_cancel_signal,
	    Failure::CancelScope::T & cancel_scope) const;

	~T () = default;

	private:
	void
	getStatusLine (IO::Interface::PeekableInputStream::T & input_stream);

	std::string
	statusLineToString () const;

	std::string version;
	uint64_t status_code;
	std::string reason_phrase;

	HeaderMap::T headers;

	std::unique_ptr<Entity::T> entity;
};
