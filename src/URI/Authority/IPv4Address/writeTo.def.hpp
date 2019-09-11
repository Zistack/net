template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream) const
{
	output_stream . print (std::to_string (this -> m_octets [0]));
	output_stream . put ('.');
	output_stream . print (std::to_string (this -> m_octets [1]));
	output_stream . put ('.');
	output_stream . print (std::to_string (this -> m_octets [2]));
	output_stream . put ('.');
	output_stream . print (std::to_string (this -> m_octets [3]));
}
