template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream) const
{
	output_stream . print (Util::encode (this -> m_registered_name));
}
