template <typename NonblockingInputStream>
struct T : Interface::WatchableInputStream::T, Failure::Cancellable::T
{
	T (NonblockingInputStream input_stream);

	char
	get () override;

	Interface::Watchable::Events::T
	events () const override;

	int
	fileDescriptor () const override;

	void
	cancel () override;

	void
	clear ();

	~T () = default;

	private:
	NonblockingInputStream input_stream;

	CancelSignal::T cancel_signal;

	size_t begin;
	size_t end;

	static const size_t BUFFER_SIZE = 4096;

	char buffer[BUFFER_SIZE];
};
