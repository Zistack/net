void
T::getRequestLine (IO::Interface::PeekableInputStream::T & input_stream)
{
	this->method = Rule::getToken (input_stream);

	IO::Util::expect (input_stream, ' ');

	this->uri = UTI::T (input_stream);

	IO::Util::expect (input_stream, ' ');

	this->version = Rule::getVersion (input_stream);

	IO::Util::expect (input_stream, "\r\n");
}
