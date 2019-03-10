struct T
{
	template <typename InputStream>
	T (InputStream && input_stream);

	T (const std::string & path_string);

	~T () = default;

	NullableString::T scheme;
	NullableString::T authority;
	std::string path;
	NullableString::T query;
	NullableString::T fragment;

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
