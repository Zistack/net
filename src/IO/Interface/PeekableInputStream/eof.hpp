bool
T::eof ()
{
	try
	{
		this->peek ();
	}
	catch (EOF::T)
	{
		return true;
	}
	return false;
}
