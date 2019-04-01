T::~T ()
{
	if (this -> tcp_socket != -1) close (this -> tcp_socket);
}
