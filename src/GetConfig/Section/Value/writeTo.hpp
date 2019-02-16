void
T::writeTo (IO::Interface::OutputStream::T & output_stream,
    size_t indentation) const
{
	output_stream.print ("{\n");

	for (auto [identifier, member] : this->members)
	{
		Util::indent (output_stream, indentation + 1);

		if (member.value)
		{
			output_stream.print ("set ");
			Rule::putIdentifier (identifier, output_stream);
			output_stream.put (' ');
			member.type->writeTo (
			    *member.value, output_stream, indentation + 1);
		}
		else
		{
			output_stream.print ("unset ");
			Rule::putIdentifier (identifier, output_stream);
		}

		output_stream.put ('\n');
	}

	Util::indent (output_stream, indentation);
	output_stream.put ('}');
}
