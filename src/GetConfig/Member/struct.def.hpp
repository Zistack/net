template
<
	typename ValueDetails,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value
>
struct T
{
	using Value = typename ValueDetails::Value;

	using ValueInterface = typename std::conditional_t
	<
		optional,
		std::optional <Value>,
		Value
	>;

	T ();

	template <typename InputStream>
	void
	readFrom (InputStream && input_stream);

	void
	validate () const;

	const ValueInterface &
	value () const;

	ValueInterface &
	value ();

	void
	unset ();

	template <typename OutputStream>
	void
	writeTo (OutputStream && output_stream, size_t indentation) const;

	~T () = default;

	template <typename OutputStream>
	static void
	printHelp
	(
		OutputStream && output_stream,
		size_t columns,
		size_t tabwidth,
		size_t indentation
	);

private:

	std::optional <Value> m_value;
};
