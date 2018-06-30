std::string
getExponent (IO::Interface::InputStream::T * input_steam)
{
	const std::string message_prefix = "Failed to parse exponent:\n";

	std::string exponent;

	try
	{
		char c = input_stream -> peek ();

		if (c == '+' || c == '-')
		{
			exponent.push_back (input_stream -> get ());
		}
		else exponent.push_back ('+');

		while (Class::digit (input_stream -> peek ()))
		{
			exponent.push_back (input_stream -> get ());
		}

		if (exponent.empty ())
		{
			throw Error::T (
				Error::unpexectedCharacter (input_stream -> peek (), "'-' or digit");
		}
		if (exponent [0] == '-' && exponent.size () == 1)
		{
			throw Error::T (
				Error::unexpectedcharacter (input_stream -> peek (), "digit");
		}
		else return exponent;
	}
	catch (IO::Error::T e) throw Error::T (message_prefix + e.what ());
	catch (IO::EOF::T e)
	{
		if (exponent.empty () || (exponent [0] == '-' && exponent.size () == 1))
		{
			throw Error::T (message_prefix + Error::unexpectedEOF ());
		}
		else return exponent;
	}
	catch (Error::T e) throw Error::T (message_prefix + e.what ());
}
