void
T::writeTo (IO::Interface::OutputStream::T & output_stream, size_t indentation)
{
	Util::indent (output_stream, indentation);
	output_stream.put ('{');

	auto it = this->members.begin ();
	for (; it != this->members.end (); ++it)
	{
		if (it != this->members.begin ()) output_stream.put (',');
		output_stream.put ('\n');

		String::T json_string (it->first);
		json_string.writeTo (output_stream, indentation + 1);

		output_stream.print (": ");

		it->second->writeTo (output_stream);
	}

	output_stream.put ('\n');

	Util::indent (output_stream, indentation);
	output_stream.put ('}');
}
