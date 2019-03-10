template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream) const
{
	output_stream.print (std::to_string (this->octets[0]));
	output_stream.put ('.');
	output_stream.print (std::to_string (this->octets[1]));
	output_stream.put ('.');
	output_stream.print (std::to_string (this->octets[2]));
	output_stream.put ('.');
	output_stream.print (std::to_string (this->octets[3]));
}
