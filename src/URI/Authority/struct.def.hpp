struct T
{
	template
	<
		typename InputStream,
		typename = std::enable_if_t <IO::IsInputStream::T <InputStream>::value>
	>
	T (InputStream && input_stream);

	T (const std::string & authority_string);

	T
	(
		const std::optional <std::string> & user_info,
		const Host::T & host,
		uint64_t port
	);

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream) const;

	std::string
	toString () const;

	~T () = default;

	std::optional <std::string> user_info;
	Host::T host;
	std::optional <uint64_t> port;

private:

	template <typename InputStream>
	void
	init (InputStream && input_stream);

	template <typename InputStream>
	void
	initHostAndPort (InputStream && input_stream);
};
