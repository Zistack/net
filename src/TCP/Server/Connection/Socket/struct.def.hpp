struct T : TCP::Socket::T
{
	~T () = default;

	private:
	T (int connection_socket);

	friend struct Server::Socket::T;
};
