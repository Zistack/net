void
T::writeTo (IO::Interface::OutputStream::T & output_stream, size_t indentation)
{
	const std::string message_prefix = "JSON::Boolean::writeTo\n";

	try
	{
		Util::indent (output_stream, indentation);
		if (this->b)
			output_stream.print ("true");
		else
			output_stream.print ("false");
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
