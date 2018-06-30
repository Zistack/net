char
T::get ()
{
	const std::string message_prefix = "HTTP::Filter::get\n";

	try
	{
		char c = input_stream->get ();

		if (c == '\n') throw IO::EncodingError (IO::Message::unexpectedCharacter ('\n'));

		if (c == '\r')
		{
			Rule::expect (input_stream, "\n");

			c = input_stream->peek ();

			// And now, the real test.  If the next character is whitespace, then we
			// want to skip whitespace and return a space.

			if (Class::whitespace (c))
			{
				skipWhitespace (input_stream);
				return ' ';
			}

			// On the other hand, if the next character is _not_ whitespace, then we
			// should really return a CRLF sequence - but we can't do that, so we
			// return '\n'.

			else return '\n';
		}

		if (control (c)) throw IO::EncodingError::T (IO::Message::unexpectedCharacter (c));
	}
	catch (IO::EOF::T e)
	{
		throw Error::T (message_prefix + Message::unexpectedEOF);
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
