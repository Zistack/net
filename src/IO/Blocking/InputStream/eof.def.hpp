template <typename NonblockingInputStream>
bool
T <NonblockingInputStream>::eof ()
{
	if (this -> eof_bit) return this -> eof_bit;

	try
	{
		this -> peek ();
	}
	catch (Failure::EndOfResource::T)
	{
		return true;
	}

	return false;
}
