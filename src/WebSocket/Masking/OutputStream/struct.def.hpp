template <typename OutputStream>
struct T
{
	T (OutputStream output_stream, Key::T masking_key);

	template
	<
		typename ProxyOutputStream = OutputStream,
		typename = std::enable_if_t
		<
			IO::IsWatchable::T <ProxyOutputStream>::value
		>
	>
	IO::Watchable::Events::T
	events () const;

	template
	<
		typename ProxyOutputStream = OutputStream,
		typename = std::enable_if_t
		<
			IO::IsWatchable::T <ProxyOutputStream>::value
		>
	>
	int
	fileDescriptor () const;

	template
	<
		typename ProxyOutputStream = OutputStream,
		typename = std::enable_if_t
		<
			Failure::IsCancellable::T <ProxyOutputStream>::value
		>
	>
	void
	cancel ();

	void
	put (char c);

	void
	write (const char * buffer, size_t count);

	void
	print (const std::string & string);

	template
	<
		typename ProxyOutputStream = OutputStream,
		typename = std::enable_if_t
		<
			IO::IsBuffered::T <ProxyOutputStream>::value
		>
	>
	void
	flush ();

	~T () = default;

private:

	OutputStream m_output_stream;

	Key::T m_masking_key;

	unsigned int m_masking_key_index;
};

template <typename OutputStream>
T (OutputStream && output_stream, Key::T masking_key) ->
	T <OutputStream>;

static_assert (IO::IsOutputStream::T <T <IO::DummyOutputStream::T>>::value);
