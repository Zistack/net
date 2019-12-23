template <typename OutputStream>
struct T <OutputStream, true> : BufferedOutputScope::T <OutputStream>
{
	using BufferedOutputScope::T <OutputStream>::T;

	~T () = default;
};

template <typename OutputStream>
struct T <OutputStream, false>
{
	template
	<
		typename ProxyOutputStream = OutputStream,
		typename = std::enable_if_t
		<
			IsOutputStream::T <ProxyOutputStream>::value
		>
	>
	T
	(
		OutputStream & output_stream,
		Failure::ExceptionStore::T & exception_store
	);

	T (const T & other) = delete;

	T (T && other) = delete;

	T &
	operator = (const T & other) = delete;

	T &
	operator = (T && other) = delete;

	~T () = default;
};

template <typename OutputStream>
T
(
	OutputStream & output_stream,
	Failure::ExceptionStore::T & exception_store
) ->
	T <OutputStream, IsBuffered::T <OutputStream>::value>;
