void
T::shutdown ()
{
	close (this -> write_file_descriptor);
	this -> write_file_descriptor = -1;
}
