template <typename InputStream>
struct T
{
	T (InputStream input_stream, Key::T masking_key);

	template
	<
		typename ProxyInputStream = InputStream,
		typename = std::enable_if_t
		<
			IO::IsWatchable::T <ProxyInputStream>::value
		>
	>
	IO::Watchable::Events::T
	events () const;

	template
	<
		typename ProxyInputStream = InputStream,
		typename = std::enable_if_t
		<
			IO::IsWatchable::T <ProxyInputStream>::value
		>
	>
	int
	fileDescriptor () const;

	template
	<
		typename ProxyInputStream = InputStream,
		typename = std::enable_if_t
		<
			Failure::IsCancellable::T <ProxyInputStream>::value
		>
	>
	void
	cancel ();

	template
	<
		typename ProxyInputStream = InputStream,
		typename = std::enable_if_t
		<
			IO::IsClearable::T <ProxyInputStream>::value
		>
	>
	void
	clear ();

	template
	<
		typename ProxyInputStream = InputStream,
		typename = std::enable_if_t
		<
			IO::IsBuffered::T <ProxyInputStream>::value
		>
	>
	bool
	isReady () const;

	char
	get ();

	char
	peek ();

	bool
	eof ();

	~T () = default;

private:

	InputStream m_input_stream;

	Key::T m_masking_key;

	unsigned int m_masking_key_index;

};

template <typename InputStream>
T (InputStream && input_stream, Key::T masking_key) -> T <InputStream>;

static_assert (IO::IsInputStream::T <T <IO::DummyInputStream::T>>::value);
