template <typename OutputStream>
template <typename ProxyOutputStream, typename>
IO::Watchable::Events::T
T <OutputStream>::events () const
{
	return this -> m_output_stream . events ();
}
