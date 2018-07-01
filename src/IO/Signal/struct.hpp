struct T : Interface::Watchable::T
{
	T ();

	void
	notify ();

	uint32_t
	events () const override;
	int
	fileDescriptor () const override;

	~T ();

	bool fired;
	int read_file_descriptor;
	int write_file_descriptor;
};
