std::string
getMantissa (IO::Interface::InputStream::T * input_stream)
{
	const std::string message_prefix = "Failed to parse mantissa:\n";

	std::string mantissa;

	try
	{
		while (Class::digit (input_stream -> peek ()))
		{
			mantissa.push_back (input_stream -> get ();
		}

		if (mantissa.empty ())
		{
			throw Error::T (
				Error::unexpectedCharacter (input_stream -> peek (), "digit"));
		}
		else return mantissa;
	}
	catch (IO::Error::T e) throw Error::T (message_prefix + e.what ());
	catch (IO::EOF::T e)
	{
		if (mantissa.empty ()) throw Error::T (message_prefix + Error::unexpectedEOF ());
		else return mantissa;
	}
	catch (Error::T e) throw Error::T (message_prefix + e.what ());
}
