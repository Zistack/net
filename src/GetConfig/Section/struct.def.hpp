template <typename V, typename ... Members>
struct T : MemberPack::T <Members ...>
{
	using Value = V;

	T () = default;

	template
	<
		typename InputStream,
		typename = std::enable_if_t <IO::IsInputStream::T <InputStream>::value>
	>
	T (InputStream && input_stream);

	template <typename InputStream>
	static Value
	readFrom (InputStream && input_stream);

	template <typename OutputStream>
	static void
	writeTo
	(
		const Value & value,
		OutputStream && output_stream,
		size_t indentation
	);

	template <typename OutputStream>
	static void
	printHelp
	(
		OutputStream && output_stream,
		size_t columns,
		size_t tabwidth,
		size_t indentation
	);

	~T () = default;

private:

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation) const;
};
