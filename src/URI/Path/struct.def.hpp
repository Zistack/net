struct T
{
	T ();

	template
	<
		typename InputStream,
		typename = std::enable_if_t <IO::IsInputStream::T <InputStream>::value>
	>
	T (InputStream && input_stream);

	T (const std::string & path_string);

	template
	<
		typename Iterable,
		typename = typename std::enable_if_t
		<
			std::is_convertible_v
			<
				decltype (* std::declval <Iterable> () . begin ()),
				std::string
			>
		>
	>
	T (Iterable && iterable, bool absolute = true);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream) const;

	std::string
	toString () const;

	~T () = default;

private:

	template <typename InputStream>
	void
	init (InputStream && input_stream);

	std::list <std::string> m_segments;
	bool m_absolute;
};
