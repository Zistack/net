void
T::shutdown ()
{
	close (this->write_file_descriptor);
	this->is_shutdown = true;
}
