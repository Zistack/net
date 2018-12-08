T::T (const std::string & field_value)
{
	IO::String::T content_length_streams (field_value);

	IO::Interface::PeekableInputStream::T & input_stream =
	    content_length_streams.peekableInputStream ();

	this->content_length = Rule::getNum (input_stream);

	if (!input_stream.eof ())
	{
		throw Failure::Error::T (message_prefix +
		    IO::Message::unexpectedCharacter (input_stream.peek ()));
	}
}
