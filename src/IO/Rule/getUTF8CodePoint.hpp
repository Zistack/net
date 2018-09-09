std::string
getUTF8CodePoint (Interface::InputStream::T * input_stream)
{
	const std::string message_prefix = "IO::Rule::getUTF8CodePoint\n";

	std::string code_point;

	char c = input_stream->get ();

	code_point.push_back (c);

	try
	{
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

		throw ExpectationException::T ();
	}
	catch (EOF::T)
	{
		if (code_point.empty ())
			throw;
		else
			throw Failure::Error::T (
			    message_prefix + Message::unexpectedEOF ());
	}
	catch (ExpectationException::T)
	{
		throw Failure::Error::T (
		    message_prefix + "Expected valid UTF-8 byte sequence\n");
	}
}
