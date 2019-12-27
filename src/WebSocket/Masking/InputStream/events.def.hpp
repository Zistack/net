template <typename InputStream>
template <typename ProxyInputStream, typename>
IO::Watchable::Events::T
T <InputStream>::events () const
{
	return this -> m_input_stream . events ();
}
