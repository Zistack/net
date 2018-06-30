T::T (std::string pattern)
{
	const std::string message_prefix = "IO::TempFile::T\n";

	try
	{
		this -> name = new char [pattern.size () + 1];
		this -> fd = mkstemp (&name);

		if (this -> fd == -1)
		{
			delete this -> name;
			throw ResourceError::T ("mkstemp: " + strerror (errno) + "\n");
		}

		this -> input_stream = FileDescriptor::InputStream::T (this -> fd);
		this -> output_stream = FileDescriptor::OutputStream::T (this -> fd);
	}
	catch (Failure::Throwable::T& e) throw e.set (message_prefix + e.what ());
}
