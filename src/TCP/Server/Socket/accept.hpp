std::unique_ptr<IO::Interface::Socket::T>
T::accept ()
{
	return std::make_unique<Connection::Socket::T> (*this);
}
