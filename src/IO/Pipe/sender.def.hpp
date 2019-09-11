FileDescriptor::Sender::T
T::sender () const
{
	return {this -> m_write_file_descriptor};
}
