T::~T ()
{
	if (!this->fired) close (this->write_file_descriptor);
	close (this->read_file_descriptor);
}
