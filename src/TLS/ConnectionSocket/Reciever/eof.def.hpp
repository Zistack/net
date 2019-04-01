bool
T::eof ()
{
	if (this -> eof_bit) return true;

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
