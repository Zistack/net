struct T
{
	template <typename InputStream>
	T (InputStream && input_stream);

	T (const std::string & authority_string);

	T (const NullableString::T & user_info,
	    const Host::T & host,
	    uint64_t port);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream) const;

	std::string
	toString () const;

	~T () = default;

	private:
	template <typename InputStream>
	void
	init (InputStream && input_stream);

	template <typename InputStream>
	void
	initHostAndPort (InputStream && input_stream);

	template <typename InputStream>
	static std::string
	getFirstPart (InputStream && input_stream);

	template <typename InputStream>
	static std::string
	getUserInfo (InputStream && input_stream);

	template <typename InputStream>
	static Host::T
	getHost (InputStream && input_stream);

	template <typename InputStream>
	static IPv6Address::T
	getIPLiteral (InputStream && input_stream);

	NullableString::T user_info;
	Host::T host;
	std::optional<uint64_t> port;
};
