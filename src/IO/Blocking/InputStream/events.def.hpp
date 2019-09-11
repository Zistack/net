template <typename NonblockingInputStream>
Watchable::Events::T
T <NonblockingInputStream>::events () const
{
	return this -> m_input_stream . events ();
}
