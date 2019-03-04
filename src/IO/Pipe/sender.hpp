FileDescriptor::Sender::T
T::sender () const
{
	return {this->write_file_descriptor};
}
