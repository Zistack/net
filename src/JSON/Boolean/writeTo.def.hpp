template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream, size_t indentation) const
{
	IO::Util::indent (std::forward <OutputStream> (output_stream), indentation);
	if (this -> m_value) output_stream . print ("true");
	else output_stream . print ("false");
}
