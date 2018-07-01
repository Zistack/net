struct T : Interface::Watchable::T
{
	T (std::string * host, std::string port, Interface::OutputStream::T * log);

	~T ();

	Socket::T *
	accept ();

	uint32_t
	events () const override;
	int
	fileDescriptor () const override;

	int file_descriptor;
};
