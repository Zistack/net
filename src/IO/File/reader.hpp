FileDescriptor::Reader::T
T::reader () const
{
	return FileDescriptor::Reader::T (this->file_descriptor);
}
