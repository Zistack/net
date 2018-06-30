bool
getBool (IO::Interface::PeekableInputStream::T <char> * input_stream)
{
	const std::string message_prefix = "Failed to parse boolean:\n";

	try
	{
		if (IO::Util::test (input_stream, 't'))
		{
			IO::Util::expect (input_stream, "true");
			return true;
		}

		if (IO::Util::test (input_stream, 'f'))
		{
			IO::Util::expect (input_stream, "false");
			return false;
		}

		throw Error::T (
			Message::unexpectedCharacter (input_stream -> peek (),
				"'true' or 'false'");
	}
	catch (IO::Error::T e) throw Error::T (message_prefix + e.what ());
	catch (EOF::T e)
	{
		throw Error::T (message_prefix + Message::unexpectedEOF ());
	}
	catch (Error::T e) throw Error::T (message_prefix + e.what ());
}
