struct T
{
	T (Type::T message_type, std::unique_ptr<HTTP::Entity::T> && body);

	void
	append (Masking::InputStream::T & input_stream,
	    uint64_t chunk_size,
	    IO::CancelSignal::T & timeout_signal);

	void
	finish ();

	void
	write (uint64_t chunk_size,
	    Masking::OutputStream::T & output_stream,
	    IO::CancelSignal::T & timeout_signal);

	Type::T
	type () const;

	off_t
	size () const;

	~T () = default;

	private:
	Type::T message_type;

	std::unique_ptr<HTTP::Entity::T> body;
};
