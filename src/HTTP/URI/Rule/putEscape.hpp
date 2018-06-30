void
putEscape (IO::Interface::OutputStream::T <char> * output_stream, char c)
{
	const std::string message_prefix = "HTTP::URI::Rule::putEscape\n";

	try
	{
		output_stream -> put ('%');
		output_stream -> print (Util::charToHex (c));
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
