T::T (const std::string & field_value)
{
	IO::String::T transfer_encoding_streams (field_value);

	IO::Interface::PeekableInputStream::T & input_stream =
	    transfer_encoding_streams.peekableInputStream ();

	auto parseSpecification =
	    [](IO::Interface::PeekableInputStream::T & input_stream) {
		    return Specification::T (input_stream);
	    };

	this->specifications =
	    Rule::getList<Specification::T, parseSpecification> (input_stream);

	if (!input_stream.eof ())
	{
		throw Failure::Error::T (message_prefix +
		    IO::Message::unexpectedCharacter (input_stream.peek ()));
	}
}
