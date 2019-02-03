std::unique_ptr<Connection::Context::T>
T::accept ()
{
	return std::make_unique<Connection::Context::T> (
	    Util::accept (this->tcp_socket, this->tls_context));
}
