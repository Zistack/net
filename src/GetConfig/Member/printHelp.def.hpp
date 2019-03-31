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
T <ValueType, optional, identifier, description, default_value>::printHelp
(
	OutputStream && output_stream,
	size_t columns,
	size_t tabwidth,
	size_t indentation
)
{
	for
	(
		std::string line :
		IO::Util::justify (description, columns - tabwidth * indentation - 2)
	)
	{
		IO::Util::indent
		(
			std::forward <OutputStream> (output_stream),
			indentation
		);
		output_stream . print ("# ");
		output_stream . print (line);
		output_stream . put ('\n');
	}

	T () . writeTo (std::forward <OutputStream> (output_stream), indentation);
}
