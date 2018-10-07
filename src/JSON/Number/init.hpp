void
T::init (IO::Interface::PeekableInputStream::T * input_stream)
{
	const std::string message_prefix = "JSON::Number::init\n";

	char c;

	try
	{
		this->base = new std::string (Rule::getBase (input_stream));

		if (input_stream->eof ()) return;

		c = input_stream->peek ();

		if (c == '.')
		{
			input_stream->get ();
			goto mantissa;
		}

		if (c == 'E' || c == 'e')
		{
			input_stream->get ();
			goto exponent;
		}

		return;

	mantissa:

		this->mantissa = new std::string (Rule::getMantissa (input_stream));

		if (input_stream->eof ()) return;

		c = input_stream->peek ();

		if (c == 'E' || c == 'e')
		{
			input_stream->get ();
			goto exponent;
		}

		return;

	exponent:

		this->exponent = new std::string (Rule::getExponent (input_stream));

		return;
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
	catch (IO::EOF::T e)
	{
		throw Failure::Error::T (
		    message_prefix + IO::Message::unexpectedEOF ());
	}
}
