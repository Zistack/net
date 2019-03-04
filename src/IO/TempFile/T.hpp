T::T () : file_descriptor (-1) {}

T::T (const std::string & pattern)
{
	const std::string message_prefix = "Failed to create temporary file\n";

	this->name = std::make_unique<char[]> (pattern.size () + 1);
	memcpy (name.get (), pattern.data (), pattern.size () + 1);

	this->file_descriptor = mkstemp (name.get ());

	if (this->file_descriptor == -1)
	{
		throw Failure::ResourceError::T (
		    message_prefix + "mkstemp: " + strerror (errno) + "\n");
	}
}

T::T (T && other) :
    name (std::move (other.name)),
    file_descriptor (other.file_descriptor)
{
	other.file_descriptor = -1;
}
