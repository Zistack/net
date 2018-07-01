std::string
getUTF8CodePoint (Interface::InputStream::T * input_stream)
{
	const std::string message_prefix = "IO::Rule::getUTF8CodePoint\n";

	std::string code_point;

	try
	{
		char c = input_stream->get ();

		code_point.push_back (c);

		if (Class::oneByte (c))
		{
			return code_point;
		}

		if (Class::twoByte (c))
		{
			code_point.push_back (
			    Util::expect (input_stream, Class::continuation));
			return code_point;
		}

		if (Class::threeByte (c))
		{
			code_point.push_back (
			    Util::expect (input_stream, Class::continuation));
			code_point.push_back (
			    Util::expect (input_stream, Class::continuation));
			return code_point;
		}

		if (Class::fourByte (c))
		{
			code_point.push_back (
			    Util::expect (input_stream, Class::continuation));
			code_point.push_back (
			    Util::expect (input_stream, Class::continuation));
			code_point.push_back (
			    Util::expect (input_stream, Class::continuation));
			return code_point;
		}

		// We should check that the code point encoded by the byte sequence is
		// valid.

		throw EncodingError::T (Message::unexpectedCharacter (
		    c, "initial byte of a valid UTF-8 code point"));
	}
	catch (const EOF::T & e)
	{
		if (code_point.empty ())
			throw e;
		else
			throw EncodingError::T (message_prefix + Message::unexpectedEOF ());
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
