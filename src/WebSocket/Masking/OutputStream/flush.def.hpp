template <typename OutputStream>
template <typename ProxyOutputStream, typename>
void
T <OutputStream>::flush ()
{
	this -> m_output_stream . flush ();
}
