void
T::writeTo (OutputStream::T * json_output_stream)
{
	const std::string message_prefix = "JSON::Number::writeTo\n";

	try
	{
		json_output_stream->print (*this->base);
		if (mantissa) json_output_stream->print ("." + *this->mantissa);
		if (exponent) json_output_stream->print ("E" + *this->exponent);
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
