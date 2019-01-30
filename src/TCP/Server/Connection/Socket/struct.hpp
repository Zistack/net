struct T : TCP::Socket::T
{
	T (Server::Socket::T & server_socket);

	~T () = default;
};
