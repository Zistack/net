Value::T *
read (IO::Interface::PeekableInputStream::T * input_stream)
{
	const std::string message_prefix = "JSON::read\n";

	try
	{
		Util::skipWhitespace (input_stream);

		char c = input_stream->peek ();

		switch (c)
		{
		case '{':
			return new Object::T (input_stream);
		case '[':
			return new Array::T (input_stream);
		case 't':
		case 'f':
			return new Boolean::T (input_stream);
		case 'n':
			return NULL;
		case '"':
			return new String::T (input_stream);
		case '+':
		case '-':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return new Number::T (input_stream);
		default:
			throw Failure::Error::T (IO::Message::unexpectedCharacter (c));
		}
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
