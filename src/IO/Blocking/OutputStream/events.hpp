template <typename NonblockingOutputStream>
Interface::Watchable::Events::T
T<NonblockingOutputStream>::events () const
{
	return this->output_stream.events ();
}
