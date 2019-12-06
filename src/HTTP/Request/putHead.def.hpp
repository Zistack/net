template <typename OutputStream>
void
T::putHead (OutputStream && output_stream) const
{
	this -> putRequestLine (std::forward <OutputStream> (output_stream));

	this -> m_headers . writeTo (std::forward <OutputStream> (output_stream));

	output_stream . print ("\r\n");
}
