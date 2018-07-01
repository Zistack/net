void
T::notify ()
{
	this->fired = true;
	close (this->write_file_descriptor);
}
