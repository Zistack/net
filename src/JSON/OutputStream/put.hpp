void
T::put (Value::T * json_value)
{
	const std::string message_prefix = "JSON::OutputStream::put\n";

	try
	{
		json_value->writeTo (this);
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}

void
T::put (char c)
{
	const std::string message_prefix = "JSON::OutputStream::put\n";

	try
	{
		this->output_stream->put (c);
		if (c == '\n') this->indent ();
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
