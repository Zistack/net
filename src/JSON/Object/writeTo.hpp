void
T::writeTo (OutputStream::T * json_output_stream)
{
	json_output_stream->open ('{');

	auto it = this->members.begin ();
	for (; it != this->members.end (); ++it)
	{
		if (it != this->members.begin ())
		{
			json_output_stream->print (",\n");
		}
		String::T json_string (it->first);
		json_output_stream->put (&json_string);
		json_output_stream->print (": ");
		json_output_stream->put (it->second);
	}

	json_output_stream->close ('}');
}
