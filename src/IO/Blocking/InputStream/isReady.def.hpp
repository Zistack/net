template <typename NonblockingInputStream>
bool
T <NonblockingInputStream>::isReady () const
{
	return this -> begin != this -> end;
}
