template <typename InputStream>
template <typename ProxyInputStream, typename>
bool
T <InputStream>::isReady () const
{
	return this -> m_input_stream . isReady ();
}
