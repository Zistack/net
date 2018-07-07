void
putEscape (OutputStream::T * json_output_stream, char32_t c)
{
	const std::string message_prefix = "JSON::Rule::putEscape\n";

	try
	{
		if (IO::Class::basicMultilingualPlane (c))
		{
			json_output_stream->print (
			    IO::Util::charToHex ((char16_t) (c & 0xFFFF)));
		}

		if (IO::Class::supplementaryPlane (c))
		{
			json_output_stream->print ("\\u");
			json_output_stream->print (IO::Util::charToHex (
			    (char16_t) (((c >> 10) & 0x03FF) | 0xD800)));
			json_output_stream->print ("\\u");
			json_output_stream->print (IO::Util::charToHex (
			    (char16_t) (((c >> 0) & 0x03FF) | 0xDC00)));
		}
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
