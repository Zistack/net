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
		CancellableSlot & request_slot,
		const TransferEncoding::Config::T & transfer_encoding_config
	) const;

	void
	check () const;

	~T () = default;

	private:
	template <typename InputStream>
	void
	getRequestLine (InputStream && input_stream);

	template <typename OutputStream>
	void
	putRequestLine (OutputStream && output_stream) const;

	std::string method;
	URI::T uri;
	std::string version;

	HeaderMap::T headers;

	std::optional <Entity::T> entity;
	std::exception_ptr e_ptr;
};
