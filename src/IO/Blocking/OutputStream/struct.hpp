template <typename NonblockingOutputStream>
struct T : Failure::Cancellable::T
{
	T (NonblockingOutputStream output_stream);

	Interface::Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	void
	put (char c);

	void
	write (const char * buffer, size_t count);

	void
	print (const std::string & string);

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

	size_t next;

	static const size_t BUFFER_SIZE = 4096;

	std::unique_ptr<char[]> buffer;

	friend struct Scope::T<T>;
};

template <typename NonblockingOutputStream>
T (NonblockingOutputStream && output_stream)->T<NonblockingOutputStream>;
