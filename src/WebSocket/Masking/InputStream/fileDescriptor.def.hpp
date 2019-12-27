template <typename InputStream>
template <typename ProxyInputStream, typename>
int
T <InputStream>::fileDescriptor () const
{
	return this -> m_input_stream . fileDescriptor ();
}
