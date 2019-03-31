template
<
	typename ValueType,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <ValueType> & default_value
>
template <typename OutputStream>
void
T
<
	ValueType,
	optional,
	identifier,
	description,
	default_value
>::writeTo (OutputStream && output_stream, size_t indentation) const
{
	IO::Util::indent (std::forward <OutputStream> (output_stream), indentation);

	if (this -> value)
	{
		output_stream . print ("set ");
		Rule::putIdentifier
		(
			identifier,
			std::forward <OutputStream> (output_stream)
		);
		output_stream . put (' ');

		this -> value -> writeTo
		(
			std::forward <OutputStream> (output_stream),
			indentation
		);
	}
	else
	{
		output_stream . print ("unset ");
		Rule::putIdentifier
		(
			identifier,
			std::forward <OutputStream> (output_stream)
		);
	}

	output_stream . put ('\n');
}
