T::~T ()
{
	if (this -> m_file_descriptor != -1)
	{
		close (this -> m_file_descriptor);
		unlink (this -> m_name . get ());
	}
}
