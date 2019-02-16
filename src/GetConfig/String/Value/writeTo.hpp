void
T::writeTo (IO::Interface::OutputStream::T & output_stream,
    size_t indentation) const
{
	output_stream.put ('"');

	for (char c : this->value)
	{
		if (c == '"')
		{
			output_stream.print ("\\\"");
		}
		else
		{
			output_stream.put (c);
		}
	}

	output_stream.put ('"');
}
