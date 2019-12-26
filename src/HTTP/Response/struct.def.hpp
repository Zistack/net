struct T
{
	T () = default;

	template <typename InputStream, typename CancellableSlot>
	T
	(
		InputStream && input_stream,
		CancellableSlot & response_slot,
		uint64_t temp_file_threshhold
	);

	T
	(
		const std::string & version,
		uint64_t status_code,
		const std::string & reason_phrase,
		const HeaderMap::T & headers,
		std::optional <Entity::T> && entity
	);

	T (T && other) = default;

	T &
	operator = (T && other) = default;

	const std::string &
	version () const;

	uint64_t
	statusCode () const;

	const std::string &
	reasonPhrase () const;

	const HeaderMap::T &
	headers () const;

	const std::optional <Entity::T> &
	entity () const;

	template <typename OutputStream, typename CancellableSlot>
	void
	writeTo
	(
		OutputStream && output_stream,
		CancellableSlot & response_slot,
		const TransferEncoding::Config::T & transfer_encoding_config
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
	getStatusLine (InputStream && input_stream);

	template <typename OutputStream>
	void
	putStatusLine (OutputStream && output_stream) const;

	template <typename OutputStream>
	void
	putHead (OutputStream && output_stream) const;

	std::string m_version;
	uint64_t m_status_code;
	std::string m_reason_phrase;

	HeaderMap::T m_headers;

	std::optional <Entity::T> m_entity;
};
