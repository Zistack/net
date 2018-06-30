char32_t
getUTF32CodePoint (Interface::InputStream::T <char32_t> * input_stream)
{
	const std::string message_prefix = "IO::Rule::getUTF32CodePoint\n";

	try
	{
		char32_t c = input_stream -> get ();

		if (Class::basicMultilingualPlane (c) || Class::supplementaryPlane (c))
		{
			return c;
		}

		throw EncodingError::T (Message::unexpectedCharacter (c, "a valid UTF-32 code point"));
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
