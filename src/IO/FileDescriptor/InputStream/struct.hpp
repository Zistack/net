struct T : Interface::WatchableInputStream::T
{
	T (int file_descriptor);

	char
	get () override;

	uint32_t
	events () const override;
	int
	fileDescriptor () const override;

	~T () = default;

	int file_descriptor;
};
