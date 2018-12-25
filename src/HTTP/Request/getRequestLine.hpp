void
T::getRequestLine (IO::Interface::PeekableInputStream::T & input_stream)
{
	this->method = Rule::getToken (input_stream);

	IO::Util::expect (input_stream, ' ');

	std::string uri_string = IO::Rule::getNotClass (input_stream, ' ');

	this->uri = URI::T (uri_string);

	IO::Util::expect (input_stream, ' ');

	this->version = Rule::getVersion (input_stream);

	IO::Util::expect (input_stream, "\r\n");
}
