std::u16string
getUTF16CodePoint (Interface::InputStream::T <char16_t> * input_stream)
{
	const std::string message_prefix = "IO::Rule::getUTF16CodePoint\n";

	try
	{
		std::u16string code_point;

		char16_t c;

		c = input_stream -> get ();

		code_point.push_back (c);

		if (Class::highSurrogate (c))
		{
			code_point.push_back (Util::expect (input_stream, Class::lowSurrogate));

			// We should check that the code point encoded by the pair is valid.
		}

		return code_point;
	}
	catch (const EOF::T& e)
	{
		if (code_point.empty ()) throw e;
		else
		{
			throw EncodingError::T (message_prefix + Message::unexpectedEOF ());
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
