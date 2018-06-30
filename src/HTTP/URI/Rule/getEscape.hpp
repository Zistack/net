char
getEscape (IO::Interface::PeekableInputStream::T <char> * input_stream)
{
	const std::string message_prefix = "HTTP::URI::Rule::getEscape\n";

	try
	{
		std::string hex;

		IO::Util::expect (input_stream, "%");

		hex.push_back (Util::expect (input_stream, Class::hex));
		hex.push_back (Util::expect (input_stream, Class::hex));

		return (char) stoul (hex, 0, 16);
	}
	catch (Faulure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
