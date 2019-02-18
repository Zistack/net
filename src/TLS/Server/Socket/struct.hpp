struct T : TLS::Socket::T, IO::Interface::Watchable::T
{
	T (const Config::Value::T & config);

	T (const T & other) = delete;
	T (T && other) = delete;

	T &
	operator= (const T & other) = delete;
	T &
	operator= (T && other) = delete;

	std::unique_ptr<Connection::Socket::T>
	accept ();

	IO::Interface::Watchable::Events::T
	events () const override;

	int
	fileDescriptor () const override;

	~T () = default;
};
