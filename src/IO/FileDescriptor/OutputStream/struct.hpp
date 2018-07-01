struct T : Interface::WatchableOutputStream::T
{
	T (int file_descriptor);

	void
	put (char c) override;

	uint32_t
	events () const override;
	int
	fileDescriptor () const override;

	~T () = default;

	int file_descriptor;
};
