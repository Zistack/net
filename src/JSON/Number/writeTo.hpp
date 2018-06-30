void
writeTo (IO::Interface::OutputStream::T <char> * output_stream)
{
	const std::string message_prefix = "Failed to write number:\n";

	try
	{
		output_stream -> print (* base);
		if (mantissa) output_stream -> print ("." + * mantissa);
		if (exponent) output_stream -> print ("E" + * exponent);
	}
	catch (IO::Error::T e) throw Error::T (message_prefix + e.what ());
}
