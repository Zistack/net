template <typename OutputStream>
template <typename ProxyOutputStream, typename>
int
T <OutputStream>::fileDescriptor () const
{
	return this -> m_output_stream . fileDescriptor ();
}
