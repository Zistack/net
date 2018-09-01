T::T (const std::string & pattern)
{
	const std::string message_prefix = "IO::TempFile::T::T\n";

	try
	{
		this->name = new char[pattern.size () + 1];
		this->file_descriptor = mkstemp (name);

		if (this->file_descriptor == -1)
		{
			delete this->name;
			throw Failure::ResourceError::T (
			    std::string ("mkstemp: ") + strerror (errno) + "\n");
		}

		this->input_stream =
		    new FileDescriptor::InputStream::T (this->file_descriptor);
		this->output_stream =
		    new FileDescriptor::OutputStream::T (this->file_descriptor);
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
