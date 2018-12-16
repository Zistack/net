struct T
{
	T (IO::Interface::PeekableInputStream::T & input_stream);

	T (const std::string & authority_string);

	T (const NullableString::T & user_info,
	    std::unique_ptr<Host::T> && host,
	    uint64_t port);

	T (const T & other);

	T (T && other) = default;

	T &
	operator= (const T & other);

	T &
	operator= (T && other) = default;

	std::string
	toString () const;

	~T () = default;

	private:
	void
	init (IO::Interface::PeekableInputStream::T & input_stream);

	void
	initHostAndPort (IO::Interface::PeekableInputStream::T & input_stream);

	static std::string
	getFirstPart (IO::Interface::PeekableInputStream::T & input_stream);

	static std::string
	getUserInfo (IO::Interface::PeekableInputStream::T & input_stream);

	static std::unique_ptr<Host::T>
	getHost (IO::Interface::PeekableInputStream::T & input_stream);

	static std::unique_ptr<IPv6Address::T>
	getIPLiteral (IO::Interface::PeekableInputStream::T & input_stream);

	NullableString::T user_info;
	std::unique_ptr<Host::T> host;
	std::optional<uint64_t> port;
};
