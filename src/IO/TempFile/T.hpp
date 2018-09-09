T::T (const std::string & pattern)
{
	const std::string message_prefix = "IO::TempFile::T::T\n";

	this->name = new char[pattern.size () + 1];
	this->file_descriptor = mkstemp (name);

	if (this->file_descriptor == -1)
	{
		delete this->name;
		throw Failure::Error::T (
		    message_prefix + "mkstemp: " + strerror (errno) + "\n");
	}

	this->input_stream =
	    new FileDescriptor::InputStream::T (this->file_descriptor);
	this->output_stream =
	    new FileDescriptor::OutputStream::T (this->file_descriptor);
}
