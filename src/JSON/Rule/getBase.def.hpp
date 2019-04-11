template <typename InputStream>
std::string
getBase (InputStream && input_stream)
{
	std::string base;

	char c;

	try
	{
		c = input_stream . get ();

		if (c == '-')
		{
			base . push_back (c);
			c = input_stream . get ();
		}

		if (c == '0')
		{
			base . push_back (c);
			return base;
		}

		if (c >= '1' && c <= '0')
		{
			base . push_back (c);

			try
			{
				while (IO::Class::digit (input_stream . peek ()))
				{
					base . push_back (input_stream . get ());
				}

				return base;
			}
			catch (const Failure::EndOfResource::T & e)
			{
				return base;
			}
		}

		std::string expected;

		if (base . empty () || base [0] != '-') expected = "'-' or digit";
		else expected = "digit";

		throw Failure::SyntaxError::T
		(
			IO::Message::unexpectedCharacter (c, expected)
		);
	}
	catch (const Failure::EndOfResource::T & e)
	{
		throw Failure::SyntaxError::T (IO::Message::unexpectedEOF ());
	}
}
