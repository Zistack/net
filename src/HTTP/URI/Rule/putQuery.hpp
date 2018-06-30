void
putQuery (IO::Interface::OutputStream::T <char> * output_stream, std::string query)
{
	const std::string message_prefix = "HTTP::URI::Rule::putQuery\n";

	try
	{
		for (char c : query)
		{
			if (Class::uric (c)) output_stream -> put (c);
			else putEscape (output_stream, c);
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
