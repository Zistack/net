template <typename NonblockingOutputStream>
struct T : Interface::WatchableOutputStream::T, Failure::Cancellable::T
{
	T (NonblockingOutputStream output_stream);

	void
	put (char c) override;

	void
	write (const char * buffer, size_t count) override;

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
	void
	flush ();

	void
	send (const char * buffer, size_t count);

	void
	open ();

	void
	close ();

	NonblockingOutputStream output_stream;
	CancelSignal::T cancel_signal;

	static const size_t BUFFER_SIZE = 4096;

	size_t next;

	char buffer[BUFFER_SIZE];

	friend struct Scope::T<T>;
};
