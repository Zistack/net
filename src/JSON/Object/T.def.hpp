template <typename InputStream>
T::T (InputStream && input_stream)
{
	try
	{
		IO::Util::expect (std::forward <InputStream> (input_stream), '{');

		Util::skipWhitespace (std::forward <InputStream> (input_stream));
		if (IO::Util::test (std::forward <InputStream> (input_stream), '}'))
		{
			input_stream . get ();
			return;
		}

		while (true)
		{
			Util::skipWhitespace (std::forward <InputStream> (input_stream));

			String::T json_string (std::forward <InputStream> (input_stream));
			std::string key = json_string . value;

			Util::skipWhitespace (std::forward <InputStream> (input_stream));
			IO::Util::expect (std::forward <InputStream> (input_stream), ':');

			std::unique_ptr <Value::T> json_value = std::make_unique <Value::T>
			(
				std::forward <InputStream> (input_stream)
			);

			this -> m_members . insert ({key, std::move (json_value)});

			Util::skipWhitespace (std::forward <InputStream> (input_stream));
			char c = input_stream . get ();

			if (c == '}') return;

			if (c == ',') continue;

			throw Failure::SyntaxError::T
			(
				IO::Message::unexpectedCharacter (c, "'}' or ','")
			);
		}
	}
	catch (Failure::EndOfResource::T & e)
	{
		throw Failure::SyntaxError::T (IO::Message::unexpectedEOF ());
	}
}
