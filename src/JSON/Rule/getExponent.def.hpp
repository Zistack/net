template <typename InputStream>
std::string
getExponent (InputStream && input_stream)
{
	std::string exponent;

	try
	{
		char c = input_stream . peek ();

		if (c == '+' || c == '-')
		{
			exponent . push_back (input_stream . get ());
		}
		else exponent . push_back ('+');

		while
		((
			c = IO::Util::test
			(
				std::forward <InputStream> (input_stream),
				IO::Class::digit
			)
		))
		{
			exponent . push_back (input_stream . get ());
		}

		if (exponent . empty ())
		{
			throw Failure::SyntaxError::T
			(
				IO::Message::unexpectedCharacter (c, "'-' or digit")
			);
		}
		if (exponent [0] == '-' && exponent . size () == 1)
		{
			throw Failure::SyntaxError::T
			(
				IO::Message::unexpectedCharacter (c, "digit")
			);
		}
		else return exponent;
	}
	catch (const Failure::EndOfResource::T & e)
	{
		if
		(
			exponent . empty () ||
			(exponent [0] == '-' && exponent . size () == 1)
		)
		{
			throw Failure::SyntaxError::T (IO::Message::unexpectedEOF ());
		}
		else return exponent;
	}
}
