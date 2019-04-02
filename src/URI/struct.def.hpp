struct T
{
	T () = default;

	template <typename InputStream>
	T (InputStream && input_stream);

	T (const std::string & uri_string);

	T
	(
		const NullableString::T & scheme,
		const std::optional <Authority::T> & authority,
		const Path::T & path,
		const NullableString::T & query,
		const NullableString::T & fragment
	);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream);

	std::string
	toString () const;

	~T () = default;

	private:
	template <typename InputStream>
	void
	init (InputStream && input_stream);

	NullableString::T scheme;
	std::optional <Authority::T> authority;
	Path::T path;
	NullableString::T query;
	NullableString::T fragment;
};
