template
<
	typename ValueType,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <ValueType> & default_value
>
struct T
{
	using ValueInterfaceType = typename std::conditional_t
	<
		optional,
		std::optional <typename ValueType::InterfaceType>,
		typename ValueType::InterfaceType
	>;

	T ();

	template <typename InputStream>
	void
	readFrom (InputStream && input_stream);

	void
	set (const ValueInterfaceType & value);

	void
	set (ValueInterfaceType && value);

	void
	unset ();

	void
	validate () const;

	ValueInterfaceType
	get () const;

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

	std::optional <ValueType> value;
};
