FileDescriptor::Writer::T
T::writerAt (off_t position)
{
	return {this -> m_file_descriptor, position};
}
