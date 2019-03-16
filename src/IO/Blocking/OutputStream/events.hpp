template <typename NonblockingOutputStream>
Watchable::Events::T
T<NonblockingOutputStream>::events () const
{
	return this->output_stream.events ();
}
