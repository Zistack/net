void
T::printHelp (IO::Interface::OutputStream::T & output_stream,
    size_t columns,
    size_t tabwidth,
    size_t indentation) const
{
	output_stream.print ("{\n");

	for (const Member::Spec::T & member : this->members)
	{
		member.printHelp (output_stream, columns, tabwidth, indentation + 1);
	}

	Util::indent (output_stream, indentation);
	output_stream.put ('}');
}
