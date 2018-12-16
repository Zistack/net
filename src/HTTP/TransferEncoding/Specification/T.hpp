T::T (IO::Interface::PeekableInputStream::T & input_stream)
{
	try
	{
		this->identifier = Rule::getToken (input_stream);

		Util::skipWhitespace (input_stream);

		while (IO::Util::test (input_stream, ';'))
		{
			input_stream.get ();

			Util::skipWhitespace (input_stream);

			std::string name = Rule::getToken (input_stream);

			if (IO::Util::test (input_stream, '='))
			{
				input_stream.get ();

				std::string value;

				if (IO::Util::test (input_stream, '"'))
				{
					value = Rule::getQuotedString (input_stream);
				}
				else
				{
					value = Rule::getToken (input_stream);
				}

				this->options.insert ({name, value});
			}
			else
				this->options.insert ({name, nullptr});

			Util::skipWhitespace (input_stream);
		}
	}
	catch (IO::EOF::T)
	{
		throw Failure::SyntaxError::T (IO::Message::unexpectedEOF ());
	}
}
