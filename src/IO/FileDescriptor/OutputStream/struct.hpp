struct T : Interface::NonblockingOutputStream::T
{
	T (int file_descriptor);
	T ();

	size_t
	write (char * buffer, size_t count) override;

	Interface::Watchable::Events::T
	events () const override;

	int
	fileDescriptor () const override;

	~T () = default;

	int file_descriptor;
};
