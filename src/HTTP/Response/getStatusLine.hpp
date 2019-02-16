void
T::getStatusLine (IO::Interface::PeekableInputStream::T & input_stream)
{
	this->version = Rule::getVersion (input_stream);

	IO::Util::expect (input_stream, ' ');

	// I could make a rule just for the status code that knows about the 3 digit
	// constraint.
	this->status_code = IO::Rule::getUInt (input_stream);

	IO::Util::expect (input_stream, ' ');

	this->reason_phrase = Rule::getText (input_stream);

	IO::Util::expect (input_stream, "\r\n");
}
