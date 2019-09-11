template <typename NonblockingOutputStream>
Watchable::Events::T
T <NonblockingOutputStream>::events () const
{
	return this -> m_output_stream . events ();
}
