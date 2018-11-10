std::unique_ptr<IO::Interface::Server::Socket::T>
T::newServerSocket ()
{
	return std::make_unique<Socket::T> (this->config);
}
