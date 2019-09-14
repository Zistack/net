struct T : TCP::Socket::T
{
	~T () = default;

private:

	using TCP::Socket::T::T;

	friend Server::Socket::T;
};
