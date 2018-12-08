void
T::getStatusLine (IO::Interface::PeekableInputStream::T & input_stream)
{
	this->status_code = Rule::getNum (input_stream);

	IO::Util::expect (input_stream, ' ');

	this->uri = URI::T (input_stream);

	IO::Util::expect (input_stream, ' ');

	this->version = Rule::getVersion (input_stream);

	IO::Util::expect (input_stream, "\r\n");
}
