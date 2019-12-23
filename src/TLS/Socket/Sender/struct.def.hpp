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

	void
	put (char c);

	void
	write (const char * buffer, size_t count);

	void
	print (const std::string & string);

	void
	flush ();

protected:

	T (size_t config_max_record_size);

	T &
	sender ();

	~T () = default;

private:

	size_t
	outputBufferSize (size_t config_max_record_size);

	void
	send (const char * buffer, size_t count);

	// Access to external members

	const Interface &
	interface () const;

	Interface &
	interface ();

	// Internal members

	IO::CancelSignal::T m_cancel_signal;

	size_t m_next;

	const size_t m_output_buffer_size;
	std::unique_ptr <char []> m_buffer;
};
