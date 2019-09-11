T::T () : m_file_descriptor (-1)
{
}

T::T (const std::string & pattern)
{
	const std::string message_prefix = "Failed to create temporary file\n";

	this -> m_name = std::make_unique <char []> (pattern . size () + 1);
	memcpy (this -> m_name . get (), pattern . data (), pattern . size () + 1);

	this -> m_file_descriptor = mkstemp (this -> m_name . get ());

	if (this -> m_file_descriptor == -1)
	{
		throw Failure::ResourceError::T
		(
			message_prefix +
				"mkstemp: " +
				Failure::Util::strerror (errno) +
				"\n"
		);
	}
}

T::T (T && other)
:	m_name (std::move (other . m_name)),
	m_file_descriptor (other . m_file_descriptor)
{
	other . m_file_descriptor = -1;
}
