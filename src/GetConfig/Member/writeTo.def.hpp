template
<
	typename ValueDetails,
	bool optional,
	const std::string & identifier,
	const std::string & description,
	const std::optional <typename ValueDetails::Value> & default_value
>
template <typename OutputStream>
void
T
<
	ValueDetails,
	optional,
	identifier,
	description,
	default_value
>::writeTo (OutputStream && output_stream, size_t indentation) const
{
	IO::Util::indent (std::forward <OutputStream> (output_stream), indentation);

	if (this -> m_value)
	{
		output_stream . print ("set ");
		Rule::putIdentifier
		(
			identifier,
			std::forward <OutputStream> (output_stream)
		);
		output_stream . put (' ');

		ValueDetails::writeTo
		(
			* this -> m_value,
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
