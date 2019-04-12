FileDescriptor::Writer::T
T::writerAt (off_t position)
{
	return {this -> file_descriptor, position};
}
