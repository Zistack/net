void
T::writeTo (OutputStream::T * json_output_stream)
{
	const std::string message_prefix = "JSON::Boolean::writeTo\n";

	try
	{
		if (this->value)
			json_output_stream->print ("true");
		else
			json_output_stream->print ("false");
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
