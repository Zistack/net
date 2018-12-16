struct T
{
	T (IO::Interface::InputStream::T & input_stream,
	    IO::CancelSignal::T & input_cancel_signal,
	    Failure::CancelScope::T & cancel_scope);

	T (const std::string & method,
	    const URI::T & uri,
	    const std::string & version,
	    const HeaderMap::T & headers,
	    std::unique_ptr<Entity::T> && entity);

	void
	writeTo (const NullableString::T & transfer_encoding_spec,
	    IO::Interface::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_cancel_signal,
	    Failure::CancelScope::T & cancel_scope) const;

	void
	check () const;

	~T () = default;

	private:
	void
	getRequestLine (IO::Interface::PeekableInputStream::T & input_stream);

	std::string
	requestLineToString () const;

	std::string method;
	URI::T uri;
	std::string version;

	HeaderMap::T headers;

	std::unique_ptr<Entity::T> entity;
	std::exception_ptr e_ptr;
};
