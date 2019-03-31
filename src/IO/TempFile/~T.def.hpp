T::~T ()
{
	if (this -> file_descriptor != -1)
	{
		close (this -> file_descriptor);
		unlink (this -> name . get ());
	}
}
