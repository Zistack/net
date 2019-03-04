FileDescriptor::Writer::T
T::writer () const
{
	return FileDescriptor::Writer::T (this->file_descriptor);
}
