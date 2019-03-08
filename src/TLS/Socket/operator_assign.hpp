T &
T::operator= (T && other)
{
	this->tcp_socket = other.tcp_socket;
	this->tls_context = std::move (other.tls_context);

	other.tcp_socket = -1;

	return *this;
}
