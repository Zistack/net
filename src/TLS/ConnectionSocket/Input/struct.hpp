struct T
{
	T (int tcp_socket);

	IO::Interface::Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	~T () = default;

	private:
	int tcp_socket;
};
