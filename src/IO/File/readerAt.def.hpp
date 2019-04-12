FileDescriptor::Reader::T
T::readerAt (off_t position) const
{
	return {this -> file_descriptor, position};
}
