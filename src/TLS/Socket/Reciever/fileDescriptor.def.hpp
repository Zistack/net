template <typename Interface>
int
T <Interface>::fileDescriptor () const
{
	return this -> interface () . tcp_socket;
}
