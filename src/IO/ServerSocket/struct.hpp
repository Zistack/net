struct T : Interface::Watchable::T
{
	T (std::string port, Interface::OutputStream::T <char> * log);

	~T ();

	Socket::T *
	accept ();

	uint32_t events () const override;
	int fd () const override;

	int fd;
};
