Error::T
valueSeparator (std::istream * json_stream)
{
	skipWhitespace (json_stream);

	std::char_traits<char>::int_type c = json_stream->get ();

	if (c == ',') return Error::NONE;
	if (eof (c)) return Error::UNEXPECTED_EOF;
	return Error::INVALID_CHARACTER;
}
