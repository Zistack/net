struct T : Interface::WatchableInputStream::T
{
	T (Interface::NonblockingInputStream::T * input_stream, Signal::T * signal);

	char
	get () override;

	Interface::Watchable::Events::T
	events () const override;

	int
	fileDescriptor () const override;

	~T () = default;

	Interface::NonblockingInputStream::T * input_stream;
	Signal::T * signal;

	static const size_t BUF_SIZE = 1024;
	size_t start;
	size_t end;
	char buffer[BUF_SIZE];
};
