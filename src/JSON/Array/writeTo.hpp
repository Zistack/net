void
T::writeTo (IO::Interface::OutputStream::T & output_stream, size_t indentation)
{
	IO::Util::indent (output_stream, indentation);
	output_stream.put ('[');

	auto it = this->members.begin ();
	for (; it != this->members.end (); ++it)
	{
		if (it != this->members.begin ()) output_stream.put (',');
		output_stream.put ('\n');

		(*it)->writeTo (output_stream, indentation + 1);
	}

	output_stream.put ('\n');

	IO::Util::indent (output_stream, indentation);
	output_stream.put (']');
}
