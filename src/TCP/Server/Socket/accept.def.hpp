std::unique_ptr <Connection::Socket::T>
T::accept ()
{
	return std::make_unique <Connection::Socket::T>
	(
		Util::accept (this -> m_file_descriptor)
	);
}
