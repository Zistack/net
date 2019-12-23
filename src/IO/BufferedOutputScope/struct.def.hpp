template <typename BufferedOutputStream>
struct T
{
	template
	<
		typename ProxyBufferedOutputStream = BufferedOutputStream,
		typename = std::enable_if_t
		<
			IsOutputStream::T <ProxyBufferedOutputStream>::value &&
				std::is_convertible_v
				<
					decltype
					(
						std::declval <ProxyBufferedOutputStream> () . flush ()
					),
					void
				>
		>
	>
	T
	(
		BufferedOutputStream & output_stream,
		Failure::ExceptionStore::T & exception_store
	);

	T (const T & other) = delete;

	T (T && other) = delete;

	T &
	operator = (const T & other) = delete;

	T &
	operator = (T && other) = delete;

	~T ();

private:

	BufferedOutputStream & m_output_stream;
	Failure::ExceptionStore::T & m_exception_store;
};

template <typename BufferedOutputStream>
T
(
	BufferedOutputStream & output_stream,
	Failure::ExceptionStore::T & exception_store
) ->
	T <BufferedOutputStream>;
