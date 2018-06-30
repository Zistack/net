void
T::notify ()
{
	this -> fired = true;
	close (this -> write_fd);
}
