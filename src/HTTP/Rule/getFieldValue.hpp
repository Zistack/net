std::string getFieldValue (
	IO::Interface::PeekableInputStream::T <char> * filtered_input_stream
)
{
	const std::string message_prefix = "HTTP::Rule::getFieldValue\n";

	try
	{
		Util::skipWhitespace (filtered_input_stream);

		std::string field_value;

		try
		{
			while (true)
			{
				char c = filtered_input_stream -> peek ();

				if (c == '\n') return text;

				field_value.push_back (filtered_input_stream -> get ());
			}
		}
		catch (IO::EOF::T e)
		{
			throw IO::EncodingError::T (IO::Message::unexpectedEOF ());
		}

		std::string::size_type end;
		for (end = 0; whitespace (c) && end > 0; --end);

		return field_value.substr (0, end);
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
