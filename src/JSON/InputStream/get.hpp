Value::T *
T::get ()
{
	char c = this->input_stream->peek ();

	switch (c)
	{
	case '{':
		return new Object::T (this);
	case '[':
		return new Array::T (this);
	case 't':
	case 'f':
		return new Boolean::T (this->input_stream);
	case 'n':
		return NULL;
	case '"':
		return new String::T (this->input_stream);
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
		return new Number::T (this->input_stream);
	default:
		throw ParsingError::T (IO::Message::unexpectedCharacter (c));
	}
}
