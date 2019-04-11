template <typename InputStream>
T::T (InputStream && input_stream)
{
	try
	{
		IO::Util::expect (std::forward <InputStream> (input_stream), '[');

		Util::skipWhitespace (std::forward <InputStream> (input_stream));
		if (IO::Util::test (std::forward <InputStream> (input_stream), ']'))
		{
			input_stream . get ();
			return;
		}

		while (true)
		{
			members . push_back
			(
				std::make_unique <Value::T>
				(
					std::forward <InputStream> (input_stream)
				)
			);

			Util::skipWhitespace (std::forward <InputStream> (input_stream));
			char c = input_stream . get ();

			if (c == ']') return;

			if (c == ',') continue;

			throw Failure::SyntaxError::T
			(
				IO::Message::unexpectedCharacter (c, "']' or ','")
			);
		}
	}
	catch (const Failure::EndOfResource::T & e)
	{
		throw Failure::SyntaxError::T (IO::Message::unexpectedEOF ());
	}
}
