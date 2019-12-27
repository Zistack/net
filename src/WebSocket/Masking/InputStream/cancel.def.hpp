template <typename InputStream>
template <typename ProxyInputStream, typename>
void
T <InputStream>::cancel ()
{
	this -> m_input_stream . cancel ();
}
