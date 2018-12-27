struct T
{
	T () = default;

	T (IO::Interface::InputStream::T & input_stream,
	    IO::CancelSignal::T & input_cancel_signal,
	    Failure::CancelScope::T & input_cancel_scope);

	T (const std::string & version,
	    uint64_t status_code,
	    const std::string & reason_phrase,
	    const HeaderMap::T & headers,
	    std::unique_ptr<Entity::T> && entity);

	T (const T & other) = delete;

	T (T && other) = default;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = default;

	void
	writeTo (
	    const TransferEncoding::Encoder::Config::T & transfer_encoding_config,
	    IO::Interface::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_cancel_signal,
	    Failure::CancelScope::T & output_cancel_scope) const;

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
