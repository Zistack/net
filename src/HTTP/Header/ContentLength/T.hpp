T::T (const std::string & field_value)
{
	IO::String::T content_length_streams (field_value);

	IO::Interface::PeekableInputStream::T & input_stream =
	    content_length_streams.peekableInputStream ();

	this->content_length = IO::Util::consume (input_stream, IO::Rule::getUInt);
}
