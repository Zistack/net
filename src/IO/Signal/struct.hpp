struct T : EPoll::Watchable::T
{
	T ();

	void notify ();

	uint32_t events () const override;
	int fd () const override;

	~T ();

	bool fired;
	int read_fd;
	int write_fd;
};
