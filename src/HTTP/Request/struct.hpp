struct T
{
	T () = default;

	T (IO::Interface::InputStream::T & input_stream,
	    IO::CancelSignal::T & input_cancel_signal,
	    Failure::CancelScope::T & input_cancel_scope,
	    uint64_t temp_file_threshhold);

	T (const std::string & method,
	    const URI::T & uri,
	    const std::string & version,
	    const HeaderMap::T & headers,
	    std::unique_ptr<Entity::T> && entity);

	T (const T & other) = delete;

	T (T && other) = default;

	T &
	operator= (const T & other) = delete;

	T &
	operator= (T && other) = default;

	void
	writeTo (IO::Interface::OutputStream::T & output_stream,
	    IO::CancelSignal::T & output_cancel_signal,
	    Failure::CancelScope::T & output_cancel_scope,
	    const TransferEncoding::Encoder::Config::Value::T &
	        transfer_encoding_config) const;

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
