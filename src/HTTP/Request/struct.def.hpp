struct T
{
	T () = default;

	template <typename InputStream, typename CancellableSlot>
	T
	(
		InputStream && input_stream,
		CancellableSlot & request_slot,
		uint64_t temp_file_threshhold
	);

	T
	(
		const std::string & method,
		const URI::T & uri,
		const std::string & version,
		const Header::Host::T & host,
		const HeaderMap::T & headers,
		std::optional <Entity::T> && entity
	);

	T (T && other) = default;

	T &
	operator = (T && other) = default;

	void
	check () const;

	const std::string &
	method () const;

	const URI::T &
	uri () const;

	const std::string &
	version () const;

	const HeaderMap::T &
	headers () const;

	const Header::Host::T &
	host () const;

	const std::optional <Entity::T> &
	entity () const;

	template <typename OutputStream, typename CancellableSlot>
	void
	writeTo
	(
		OutputStream && output_stream,
		CancellableSlot & request_slot,
		const TransferEncoding::Config::T & transfer_encoding_config =
			TransferEncoding::Config::T ()
	) const;

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream) const;

	std::string
	toString () const;

	~T () = default;

private:

	template <typename InputStream>
	void
	getRequestLine (InputStream && input_stream);

	template <typename OutputStream>
	void
	putRequestLine (OutputStream && output_stream) const;

	template <typename OutputStream>
	void
	putHead (OutputStream && output_stream) const;

	std::exception_ptr m_e_ptr;

	std::string m_method;
	URI::T m_uri;
	std::string m_version;

	Header::Host::T m_host;

	HeaderMap::T m_headers;

	std::optional <Entity::T> m_entity;
};
