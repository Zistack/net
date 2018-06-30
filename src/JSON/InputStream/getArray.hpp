void
getArray (std::function <void ()> getValue)
{
	const std::string message_prefix = "Failed to parse array:\n";

	try
	{
		Util::skipWhitespace (input_stream);

		IO::Util::expect (input_stream, '[');

		Util::skipWhitespace (input_stream);

		if (IO::Util::test (input_stream, ']'))
		{
			input_stream -> get ();
			return;
		}

		while (true)
		{
			getValue ();

			Util::skipWhitespace (input_stream);

			if (IO::Util::test (input_stream, ']'))
			{
				input_stream -> get ();
				return;
			}

			IO::Util::expect (input_stream, ','));

			Util::skipWhitespace (input_stream);
		}
	}
	catch (IO::Error::T e) throw Error::T (message_prefix + e.what ());
	catch (EOF::T e)
	{
		throw Error::T (message_prefix + Message::unexpectedEOF ());
	}
	catch (Error::T e) throw Error::T (message_prefix + e.what ());
}
