struct T
{
	template <typename InputStream>
	T (InputStream && input_stream);

	~T () = default;

	std::string m_identifier;
	std::unordered_map<std::string, NullableString::T> m_options;
};
