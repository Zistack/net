template <typename InputStream>
char16_t
getCodePoint (InputStream && input_stream)
{
	char c;
	char16_t code_point = 0;

	try
	{
		unsigned int i;
		for (i = 4; i > 0; -- i)
		{
			c = IO::Util::expect
			(
				std::forward <InputStream> (input_stream),
				IO::Class::hex
			);

			code_point |=
				(char16_t) (IO::Util::hexToNibble (c) << ((i - 1) * 4));
		}

		return code_point;
	}
	catch (const Failure::EndOfResource::T & e)
	{
		throw Failure::SyntaxError::T (IO::Message::unexpectedEOF ());
	}
}
