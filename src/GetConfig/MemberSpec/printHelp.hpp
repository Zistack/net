void
T::printHelp (IO::Interface::OutputStream::T & output_stream,
    size_t columns,
    size_t tabwidth,
    size_t indentation) const
{
	for (std::string line : IO::Util::justify (
	         this->description, columns - tabwidth * indentation - 2))
	{
		Util::indent (output_stream, indentation);
		output_stream.print ("# ");
		output_stream.print (line);
		output_stream.put ('\n');
	}

	if (this->default_value)
	{
		Util::indent (output_stream, indentation);
		output_stream.print ("set ");
		output_stream.print (this->identifier);
		output_stream.put (' ');
		this->type->writeTo (*this->default_value, output_stream, indentation);
		output_stream.put ('\n');
	}
	else
	{
		Util::indent (output_stream, indentation);
		output_stream.print ("unset ");
		output_stream.print (this->identifier);
		output_stream.put ('\n');
	}
}
