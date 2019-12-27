template <typename OutputStream>
template <typename ProxyOutputstream, typename>
void
T <OutputStream>::cancel ()
{
	this -> m_output_stream . cancel ();
}
