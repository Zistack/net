void
T::initHostAndPort (IO::Interface::PeekableInputStream::T & input_stream)
{
	this->host = std::move (getHost (input_stream));

	if (IO::Util::test (input_stream, ':'))
	{
		input_stream.get ();

		this->port = IO::Rule::getUInt (input_stream);
	}
}
