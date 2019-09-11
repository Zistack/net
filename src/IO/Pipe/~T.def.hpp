T::~T ()
{
	if (this -> m_read_file_descriptor != -1)
	{
		close (this -> m_read_file_descriptor);
	}
	if (this -> m_write_file_descriptor != -1)
	{
		close (this -> m_write_file_descriptor);
	}
}
