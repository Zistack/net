bool
eof ()
{
	try peek ();
	catch (EOF::T) return true;
	return false;
}
