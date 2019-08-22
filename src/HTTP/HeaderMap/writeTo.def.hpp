template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream) const
{
	for (auto && [field_name, field_value] : this -> m_map)
	{
		output_stream . print (field_name);
		output_stream . print (": ");
		output_stream . print (field_value);
		output_stream . print ("\r\n");
	}
}
