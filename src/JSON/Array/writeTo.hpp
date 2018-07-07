void
T::writeTo (OutputStream::T * json_output_stream)
{
	json_output_stream->open ('[');

	auto it = this->members.begin ();
	for (; it != this->members.end (); ++it)
	{
		if (it != this->members.begin ())
		{
			json_output_stream->print (",\n");
		}
		json_output_stream->put (*it);
	}

	json_output_stream->close (']');
}
