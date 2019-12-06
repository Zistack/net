template <typename OutputStream>
void
T::putStatusLine (OutputStream && output_stream) const
{
	output_stream . print (this -> m_version);

	output_stream . put (' ');

	output_stream . print (std::to_string (this -> m_status_code));

	output_stream . put (' ');

	output_stream . print (this -> m_reason_phrase);

	output_stream . print ("\r\n");
}
