IO::FileDescriptor::Input::T
T::input () const
{
	return {this -> m_tcp_socket};
}
