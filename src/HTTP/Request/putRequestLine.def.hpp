template <typename OutputStream>
void
T::putRequestLine (OutputStream && output_stream) const
{
	output_stream . print (this -> m_method);

	output_stream . put (' ');

	this -> m_uri . writeTo (std::forward <OutputStream> (output_stream));

	output_stream . put (' ');

	output_stream . print (this -> m_version);
	output_stream . print ("\r\n");
}
