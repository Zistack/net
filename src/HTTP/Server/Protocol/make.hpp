std::unique_ptr<IO::Interface::Protocol::T>
T::make ()
{
	return std::make_unique<Connection::Protocol::T> (
	    this->config, this->responder);
}
