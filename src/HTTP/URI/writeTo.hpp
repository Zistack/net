void
T::writeTo (IO::Interface::OutputStream::T <char> * output_stream)
{
	const std::string message_prefix = "HTTP::URI::writeTo\n";

	try
	{
		output_stream -> print (scheme);
		output_stream -> print (":\/\/");
		output_stream -> print (host);
		output_stream -> put (':');
		output_stream -> print (std::to_string (port));
		Rule::putAbsolutePath (output_stream, absolute_path);
		if (! query.empty ())
		{
			output_stream -> put ('?');
			Rule::putQuery (output_stream, query);
		}
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
