T::~T ()
{
	close (this->read_file_descriptor);
	if (!this->is_shutdown) close (this->write_file_descriptor);
}
