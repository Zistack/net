struct T : WatchableInputStream::T <char>
{
	T (int fd);

	char get () override;

	uint32_t events () const override;
	int fd () const override;

	~T () = default;

	int fd;
};
