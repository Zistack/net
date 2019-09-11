IO::FileDescriptor::Output::T
T::output () const
{
	return {this -> m_tcp_socket};
}
