T::~T ()
{
	close (this->read_file_descriptor);
	close (this->write_file_descriptor);
}
