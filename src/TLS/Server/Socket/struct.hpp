struct T : TLS::Socket::T, IO::Interface::Watchable::T
{
	T (const Config::T & config);

	std::unique_ptr<Connection::Socket::T>
	accept ();

	IO::Interface::Watchable::Events::T
	events () const override;

	int
	fileDescriptor () const override;

	~T () = default;
};
