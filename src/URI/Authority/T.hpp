template <typename InputStream>
T::T (InputStream && input_stream)
{
	this->init (std::forward<InputStream> (input_stream));
}

T::T (const std::string & authority_string)
{
	IO::String::Reader::T input_stream (authority_string);
	this->init (input_stream);
	IO::Util::expectEOF (input_stream);
}

T::T (const NullableString::T & user_info,
    const Host::T & host,
    uint64_t port) :
    user_info (user_info),
    host (host),
    port (port)
{
}
