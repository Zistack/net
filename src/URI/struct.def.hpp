struct T
{
	T () = default;

	template
	<
		typename InputStream,
		typename = std::enable_if_t <IO::IsInputStream::T <InputStream>::value>
	>
	T (InputStream && input_stream);

	T (const std::string & uri_string);

	T
	(
		const std::optional <std::string> & scheme,
		const std::optional <Authority::T> & authority,
		const Path::T & path,
		const std::optional <std::string> & query,
		const std::optional <std::string> & fragment
	);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream) const;

	std::string
	toString () const;

	~T () = default;

	std::optional <std::string> scheme;
	std::optional <Authority::T> authority;
	Path::T path;
	std::optional <std::string> query;
	std::optional <std::string> fragment;

private:

	template <typename InputStream>
	void
	init (InputStream && input_stream);
};
