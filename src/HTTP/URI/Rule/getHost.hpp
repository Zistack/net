std::string
getHost (IO::Interface::PeekableInputStream::T <char> * input_stream)
{
	const std::string message_prefix = "HTTP::URI::Rule::getHost\n";

	try
	{
		char c = input_stream -> peek ();

		if (alpha (c)) return getHostName (input_stream);

		if (digit (c)) return getIPv4Address (input_stream);

		throw IO::EncodingError (
			IO::Message::unexpectedCharacter (c, "Hostname or IP address")
		);
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
