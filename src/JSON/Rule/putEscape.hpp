void
putEscape (IO::Interface::OutputStream::T * output_stream, char32_t c)
{
	const std::string message_prefix = "JSON::Rule::putEscape\n";

	try
	{
		if (IO::Class::basicMultilingualPlane (c))
		{
			output_stream->print (
			    IO::Util::charToHex ((char16_t) (c & 0xFFFF)));
		}

		if (IO::Class::supplementaryPlane (c))
		{
			output_stream->print ("\\u");
			output_stream->print (IO::Util::charToHex (
			    (char16_t) (((c >> 10) & 0x03FF) | 0xD800)));
			output_stream->print ("\\u");
			output_stream->print (IO::Util::charToHex (
			    (char16_t) (((c >> 0) & 0x03FF) | 0xDC00)));
		}
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
