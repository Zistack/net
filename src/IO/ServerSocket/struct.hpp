struct T : Interface::Watchable::T
{
	T (const char * host, const char * port, Interface::OutputStream::T * log);
	T (const T & other) = delete;

	~T ();

	Socket::T *
	accept ();

	Interface::Watchable::Events::T
	events () const override;

	int
	fileDescriptor () const override;

	int file_descriptor;
};
