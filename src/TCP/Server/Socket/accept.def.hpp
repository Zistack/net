std::unique_ptr <Connection::Socket::T>
T::accept ()
{
	return std::unique_ptr <Connection::Socket::T>
	(
		new Connection::Socket::T (Util::accept (this -> m_file_descriptor))
	);
}
