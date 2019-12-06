template <typename OutputStream>
void
T::writeTo
(
	const Value & value,
	OutputStream && output_stream,
	size_t indentation
)
{
	value . writeTo (std::forward <OutputStream> (output_stream));
}
