std::unique_ptr<IO::Interface::Socket::T>
T::newSocket ()
{
	return std::make_unique<Socket::T> (this->config);
}
