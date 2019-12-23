struct T
{
	template
	<
		typename InputStream,
		typename = std::enable_if_t <IO::IsInputStream::T <InputStream>::value>
	>
	T (InputStream && input_stream);

	T (const std::string & path_string);

	~T () = default;

	std::optional <std::string> scheme;
	std::optional <std::string> authority;
	std::string path;
	std::optional <std::string> query;
	std::optional <std::string> fragment;

private:

	template <typename InputStream>
	void
	init (InputStream && input_stream);

	template <typename InputStream>
	static std::string
	getFirstPart (InputStream && input_stream);

	template <typename InputStream>
	static std::string
	getAuthorityPart (InputStream && input_stream);

	template <typename InputStream>
	static std::string
	getPathPart (InputStream && input_stream);

	template <typename InputStream>
	static std::string
	getQueryPart (InputStream && input_stream);

	template <typename InputStream>
	static std::string
	getFragmentPart (InputStream && input_stream);
};
