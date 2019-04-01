bool
T::spurious ()
{
	bool spurious_read = this -> spurious_read;
	this -> spurious_read = false;
	return spurious_read;
}
