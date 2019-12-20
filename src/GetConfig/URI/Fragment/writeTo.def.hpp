template <typename OutputStream>
void
T::writeTo
(
	const Value & value,
	OutputStream && output_stream,
	size_t indentation
)
{
	output_stream . print (value);
}
