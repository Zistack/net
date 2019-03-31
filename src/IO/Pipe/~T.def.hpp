T::~T ()
{
	if (this -> read_file_descriptor != -1)
	{
		close (this -> read_file_descriptor);
	}
	if (this -> write_file_descriptor != -1)
	{
		close (this -> write_file_descriptor);
	}
}
