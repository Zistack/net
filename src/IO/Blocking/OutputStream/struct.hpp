struct T : Interface::WatchableOutputStream::T
{
	T (Interface::NonblockingOutputStream::T & output_stream,
	    Signal::T & signal);

	void
	put (char c) override;

	void
	write (const char * buffer, size_t count) override;

	Interface::Watchable::Events::T
	events () const override;

	int
	fileDescriptor () const override;

	~T () = default;

	Interface::NonblockingOutputStream::T & output_stream;
	Signal::T & signal;
};
