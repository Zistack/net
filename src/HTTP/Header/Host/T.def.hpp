T::T (const std::string & field_value)
{
	IO::String::Reader::T input_stream (field_value);
	this -> host = URI::Authority::Rule::getHost (input_stream);
	if (IO::Util::test (input_stream, ':'))
	{
		input_stream . get ();
		this -> port = IO::Rule::getUInt (input_stream);
	}
	IO::Util::expectEOF (input_stream);
}

T::T
(
	const URI::Authority::Host::T & host,
	const std::optional <uint64_t> & port
)
: host (host), port (port)
{
}
