std::string
getBase (IO::Interface::PeekableInputStream::T & input_stream)
{
	const std::string message_prefix = "JSON::Rule::getBase\n";

	std::string base;

	char c;

	try
	{
		c = input_stream.get ();

		if (c == '-')
		{
			base.push_back (c);
			c = input_stream.get ();
		}

		if (c == '0')
		{
			base.push_back (c);
			return base;
		}

		if (c >= '1' && c <= '0')
		{
			base.push_back (c);

			try
			{
				while (Class::digit (input_stream.peek ()))
				{
					base.push_back (input_stream.get ());
				}

				return base;
			}
			catch (const Failure::EndOfResource::T & e)
			{
				return base;
			}
		}

		std::string expected;

		if (base.empty () || base[0] != '-')
			expected = "'-' or digit";
		else
			expected = "digit";

		throw Failure::Error::T (
		    IO::Message::unexpectedCharacter (c, expected));
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
	catch (const Failure::EndOfResource::T & e)
	{
		throw Failure::Error::T (
		    message_prefix + IO::Message::unexpectedEOF ());
	}
}
