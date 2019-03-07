template <typename NonblockingInputStream>
struct T : Failure::Cancellable::T
{
	T (NonblockingInputStream input_stream);

	Interface::Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	char
	get ();

	char
	peek ();

	bool
	eof ();

	void
	cancel () override;

	void
	clear ();

	~T () = default;

	private:
	void
	refill ();

	NonblockingInputStream input_stream;

	CancelSignal::T cancel_signal;

	size_t begin;
	size_t end;

	static const size_t BUFFER_SIZE = 4096;

	std::unique_ptr<char[]> buffer;

	bool eof_bit;
};

template <typename NonblockingInputStream>
T (NonblockingInputStream && input_stream)->T<NonblockingInputStream>;
