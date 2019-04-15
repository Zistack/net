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

	template <typename OutputStream, typename CancellableSlot>
	void
	writeTo
	(
		OutputStream && output_stream,
		CancellableSlot & response_slot,
		const TransferEncoding::Config::T & transfer_encoding_config
	) const;

	~T () = default;

private:

	template <typename InputStream>
	void
	getStatusLine (InputStream && input_stream);

	template <typename OutputStream>
	void
	putStatusLine (OutputStream && output_stream) const;

	std::string version;
	uint64_t status_code;
	std::string reason_phrase;

	HeaderMap::T headers;

	std::optional <Entity::T> entity;
};
