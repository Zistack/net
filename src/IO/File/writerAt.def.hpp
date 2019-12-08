FileDescriptor::Writer::T
T::writerAt (size_t position)
{
	return {this -> m_file_descriptor, position};
}
