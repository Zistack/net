void
T::writeTo (IO::Interface::OutputStream::T & output_stream, size_t indentation)
{
	const std::string message_prefix = "JSON::Number::writeTo\n";

	try
	{
		IO::Util::indent (output_stream, indentation);
		output_stream.print (this->base);
		if (mantissa) output_stream.print ("." + this->mantissa.stdString ());
		if (exponent) output_stream.print ("E" + this->exponent.stdString ());
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
