template <typename Interface>
struct T
{
	IO::Watchable::Events::T
	events () const;

	int
	fileDescriptor () const;

	void
	cancel ();

	void
	clear ();

	bool
	isReady () const;

	char
	get ();

	char
	peek ();

	bool
	eof ();

protected:

	T ();

	T &
	reciever ();

	~T () = default;

private:

	void
	refill ();

	// Access to external members

	const Interface &
	interface () const;

	Interface &
	interface ();

	// Internal members

	IO::CancelSignal::T m_cancel_signal;

	size_t m_begin;
	size_t m_end;

	const size_t m_input_buffer_size;
	std::unique_ptr <char []> m_buffer;

	bool m_eof_bit;
};
