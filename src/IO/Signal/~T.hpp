T::~T ()
{
	if (! this -> fired) close (this -> write_fd);
	close (this -> read_fd);
}
