T::T (IO::Interface::PeekableInputStream::T & input_stream)
{
	init (input_stream);
}

T::T (const std::string & authority_string)
{
	IO::Util::consume (authority_string,
	    [this](IO::Interface::PeekableInputStream::T & input_stream) {
		    this->init (input_stream);
	    });
}

T::T (const NullableString::T & user_info,
    std::unique_ptr<Host::T> && host,
    uint64_t port) :
    user_info (user_info),
    host (std::move (host)),
    port (port)
{
}

T::T (const T & other) :
    user_info (other.user_info),
    host (other.host->clone ()),
    port (other.port)
{
}
