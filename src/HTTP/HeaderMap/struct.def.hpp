struct T
{
	T () = default;

	template
	<
		typename InputStream,
		typename = std::enable_if_t <IO::IsInputStream::T <InputStream>::value>
	>
	T (InputStream && input_stream);

	template
	<
		typename Iterable,
		typename = typename std::enable_if_t
		<
			std::is_convertible_v
			<
				decltype (* std::declval <Iterable> () . begin ()),
				std::pair <std::string, std::string>
			>
		>
	>
	T (const Iterable & iterable);

	bool
	contains (const std::string & field_name) const;

	const std::string &
	at (const std::string & field_name) const;

	std::string
	pop (const std::string & field_name);

	void
	insert (const std::string & field_name, const std::string & field_value);

	void
	remove (const std::string & field_name);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream) const;

	~T () = default;

private:

	std::unordered_map <std::string, std::string> m_map;
};
