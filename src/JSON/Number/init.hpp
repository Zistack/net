void
init (IO::Interface::PeekableInputStream::T <char> * input_stream)
{
	const std::string message_prefix = "Failed to parse number:\n";

	char c;

	try
	{
		base = new std::string (Rule::getBase (input_stream));

		if (input_stream -> eof ()) return;

		c = input_stream -> peek ();

		if (c == '.')
		{
			input_stream -> get ();
			goto mantissa;
		}

		if (c == 'E' || c == 'e')
		{
			input_stream -> get ();
			goto exponent;
		}

		return;

mantissa:

		mantissa = new std::string (Rule::getMantissa (input_stream));

		if (input_stream -> eof ()) return;

		c = input_stream -> peek ();

		if (c == 'E' || c == 'e')
		{
			input_stream -> get ();
			goto exponent;
		}

		return;

exponent:

		exponent = new std::string (Rule::getExponent (input_stream));

		return;
	}
	catch (IO::Error::T e) throw Error::T (message_prefix + e.what ());
	catch (IO::EOF::T e)
	{
		throw Error::T (message_prefix + IO::Message::unexpectedEOF ());
	}
	catch (Error::T e) throw Error::T (message_prefix + e.what ());
}
