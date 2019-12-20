template <typename OutputStream>
void
T::writeTo
(
	const Value & value,
	OutputStream && output_stream,
	size_t indentation
)
{
	::URI::Authority::Host::writeTo
	(
		value,
		std::forward <OutputStream> (output_stream)
	);
}
