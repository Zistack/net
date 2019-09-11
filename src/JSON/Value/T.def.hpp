template <typename InputStream>
T::T (InputStream && input_stream)
{
	Util::skipWhitespace (std::forward <InputStream> (input_stream));

	char c = input_stream . peek ();

	switch (c)
	{
	case '{':

		this -> m_contents . emplace
		(
			std::in_place_type <Object::T>,
			std::forward <InputStream> (input_stream)
		);

	case '[':

		this -> m_contents . emplace
		(
			std::in_place_type <Array::T>,
			std::forward <InputStream> (input_stream)
		);

	case 't':
	case 'f':

		this -> m_contents . emplace
		(
			std::in_place_type <Boolean::T>,
			std::forward <InputStream> (input_stream)
		);

	case 'n':

		// Gotta grab the token, but also we just set ourselves to null.

	case '"':

		this -> m_contents . emplace
		(
			std::in_place_type <String::T>,
			std::forward <InputStream> (input_stream)
		);

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

		this -> m_contents . emplace
		(
			std::in_place_type <Number::T>,
			std::forward <InputStream> (input_stream)
		);

	default:

		throw Failure::SyntaxError::T
		(
			IO::Message::unexpectedCharacter (c)
		);
	}
}
