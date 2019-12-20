template <typename Interface>
bool
T <Interface>::eof ()
{
	if (this -> m_eof_bit) return true;

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
