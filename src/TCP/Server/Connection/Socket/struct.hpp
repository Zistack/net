struct T : TCP::Socket::T
{
	T (Server::Socket::T & server_socket);

	~T () override = default;

	private:
	static int
	newSocket (Server::Socket::T & server_socket);
};
