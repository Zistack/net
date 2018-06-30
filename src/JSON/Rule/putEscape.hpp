void
putEscape (IO::Interface::OutputStream::T <char> * output_stream, char32_t c)
{
	const std::string message_prefix = "Failed to print escape sequence:\n";

	try
	{
		if (IO::Class::basicMultilingualPlane (c))
		{
			output_stream -> print (IO::Util::utf16CodePointToHex ((char16_t) (c & 0xFFFF)));
		}

		if (IO::Class::supplementaryPlane (c))
		{
			output_stream -> print ("\\u");
			output_stream -> print (
				IO::Util::utf16CodePointToHex (
					(char16_t) (((c >> 10) & 0x03FF) | 0xD800)));
			output_stream -> print ("\\u");
			output_stream -> print (
				IO::Util::utf16CodePointToHex (
					(char16_t) (((c >> 0) & 0x03FF) | 0xDC00)));
		}
	}
	catch (Error::T e) throw Error::T (message_prefix + e.what ());
}
