struct T
{
	template
	<
		typename InputStream,
		typename = std::enable_if_t
		<
			IO::TypeTraits::IsInputStream::T <InputStream>::value
		>
	>
	T (InputStream && input_stream);

	~T () = default;

	std::string identifier;
	std::unordered_map <std::string, std::optional <std::string>> options;
};
