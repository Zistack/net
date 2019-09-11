template <typename NonblockingInputStream>
bool
T <NonblockingInputStream>::eof ()
{
	if (this -> m_eof_bit) return this -> m_eof_bit;

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
