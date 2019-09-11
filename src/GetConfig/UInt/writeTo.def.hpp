template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream) const
{
	IO::Rule::putUInt
	(
		this -> m_value,
		std::forward <OutputStream> (output_stream)
	);
}
