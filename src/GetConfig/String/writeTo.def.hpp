template <typename OutputStream>
void
T::writeTo
(
	const Value & value,
	OutputStream && output_stream,
	size_t indentation
)
{
	output_stream . put ('"');
	for (char c : value)
	{
		if (c == '"')
		{
			output_stream . print ("\"");
		}
		else
		{
			output_stream . put (c);
		}
	}
	output_stream . put ('"');
}
