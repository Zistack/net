template <typename InputStream>
std::string
getMantissa (InputStream && input_stream)
{
	std::string mantissa;

	try
	{
		while (IO::Class::digit (input_stream . peek ()))
		{
			mantissa . push_back (input_stream . get ());
		}

		if (mantissa . empty ())
		{
			throw Failure::SyntaxError::T
			(
				IO::Message::unexpectedCharacter
				(
					input_stream . peek (),
					"digit"
				)
			);
		}
		else return mantissa;
	}
	catch (const Failure::EndOfResource::T & e)
	{
		if (mantissa . empty ())
		{
			throw Failure::SyntaxError::T (IO::Message::unexpectedEOF ());
		}
		else return mantissa;
	}
}
