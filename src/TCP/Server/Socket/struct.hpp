struct T : IO::Interface::Server::Socket::T
{
	T (const Config::T & config);

	T (const T & other) = delete;
	T (T && other) = delete;

	T &
	operator= (const T & other) = delete;
	T &
	operator= (T && other) = delete;

	std::unique_ptr<IO::Interface::Socket::T>
	accept () override;

	IO::Interface::Watchable::Events::T
	events () const override;

	int
	fileDescriptor () const override;

	~T () override;

	private:
	static int
	newSocket (const Config::T & config);

	int file_descriptor;
};
