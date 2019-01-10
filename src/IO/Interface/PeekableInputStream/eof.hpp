bool
T::eof ()
{
	try
	{
		this->peek ();
	}
	catch (Failure::EndOfResource::T)
	{
		return true;
	}
	return false;
}
