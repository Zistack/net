void
putPChars (IO::Interface::OutputStream::T <char> * output_stream, std::string pchars)
{
	const std::string message_prefix = "HTTP::URI::Rule::putPChars\n";

	try
	{
		for (char c : pchars)
		{
			if (Class::pchar (c)) output_stream -> put (c);
			else putEscape (output_stream, c);
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
