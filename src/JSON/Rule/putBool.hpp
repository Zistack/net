void
putBool (IO::Interface::OutputStream::T <char> * output_stream, bool b)
{
	const std::string message_prefix = "Failed to write boolean value:\n";

	try
	{
		if (b) output_stream -> print ("true");
		else output_stream -> print ("false");
	}
	catch (IO::Error::T e) throw Error::T (message_prefix + e.what ());
}
