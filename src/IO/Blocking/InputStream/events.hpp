template <typename NonblockingInputStream>
Interface::Watchable::Events::T
T<NonblockingInputStream>::events () const
{
	return this->input_stream.events ();
}
