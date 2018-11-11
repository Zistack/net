T::T (IO::Interface::PeekableInputStream::T & input_stream)
{
	const std::string message_prefix = "JSON::Boolean::T\n";

	try
	{
		char c = input_stream.peek ();

		if (c == 't')
		{
			IO::Util::expect (input_stream, "true");
			this->b = true;
		}

		if (c == 'f')
		{
			IO::Util::expect (input_stream, "false");
			this->b = false;
		}

		throw Failure::Error::T (IO::Message::unexpectedCharacter (c));
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}

T::T (bool b) : b (b) {}
