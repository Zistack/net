template <typename OutputStream>
void
T::writeTo
(
	const Value & value,
	OutputStream && output_stream,
	size_t indentation
)
{
	IO::Rule::putUInt (value, std::forward <OutputStream> (output_stream));
}
