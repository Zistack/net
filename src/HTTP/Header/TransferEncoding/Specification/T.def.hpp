template <typename InputStream>
T::T (InputStream && input_stream)
{
	try
	{
		this -> identifier =
			Rule::getToken (std::forward <InputStream> (input_stream));

		Util::skipWhitespace (std::forward <InputStream> (input_stream));

		while (IO::Util::test (std::forward <InputStream> (input_stream), ';'))
		{
			input_stream . get ();

			Util::skipWhitespace (std::forward <InputStream> (input_stream));

			std::string name =
				Rule::getToken (std::forward <InputStream> (input_stream));

			if (IO::Util::test (std::forward <InputStream> (input_stream), '='))
			{
				input_stream . get ();

				std::string value;

				if
				(
					IO::Util::test
					(
						std::forward <InputStream> (input_stream),
						'"'
					)
				)
				{
					value = Rule::getQuotedString
					(
						std::forward <InputStream> (input_stream)
					);
				}
				else
				{
					value = Rule::getToken
					(
						std::forward <InputStream> (input_stream)
					);
				}

				this -> options . insert ({name, value});
			}
			else this -> options . insert ({name, nullptr});

			Util::skipWhitespace (std::forward <InputStream> (input_stream));
		}
	}
	catch (Failure::EndOfResource::T)
	{
		throw Failure::SyntaxError::T (IO::Message::unexpectedEOF ());
	}
}
