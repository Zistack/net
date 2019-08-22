template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream)
{
	output_stream . print (this -> m_name);
	if (this -> m_version)
	{
		output_stream . put ('/');
		output_stream . print (this -> m_version . stdString ());
	}
}
