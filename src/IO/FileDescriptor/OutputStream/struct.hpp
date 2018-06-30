struct T : WatchableOutputStream::T <char>
{
	T (int fd);

	void put (char c) override;

	uint32_t events () const override;
	int fd () const override;

	~T () = default;

	int fd;
};
