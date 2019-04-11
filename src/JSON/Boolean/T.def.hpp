template <typename InputStream>
T::T (InputStream && input_stream)
{
	char c = input_stream . peek ();

	if (c == 't')
	{
		IO::Util::expect (std::forward <InputStream> (input_stream), "true");
		this -> b = true;
	}

	if (c == 'f')
	{
		IO::Util::expect (std::forward <InputStream> (input_stream), "false");
		this -> b = false;
	}

	throw Failure::SyntaxError::T (IO::Message::unexpectedCharacter (c));
}

T::T (bool b) : b (b)
{
}
