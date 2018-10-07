struct T : IO::Interface::ServerSocket::T
{
	T (const char * host, const char * port);
	T (const Config::T & config);
	T (JSON::Value::T * config_value);

	T (const T & other) = delete;

	Client::T *
	accept () override;

	IO::Interface::Watchable::Events::T
	events () const override;

	int
	fileDescriptor () const override;

	~T () override;

	int file_descriptor;
};
