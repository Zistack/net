template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream) const
{
	IO::Rule::putUInt
	(
		this -> value,
		std::forward <OutputStream> (output_stream)
	);
}
