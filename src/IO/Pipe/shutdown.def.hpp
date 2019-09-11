void
T::shutdown ()
{
	close (this -> m_write_file_descriptor);
	this -> m_write_file_descriptor = -1;
}
