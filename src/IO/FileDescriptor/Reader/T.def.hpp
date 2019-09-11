T::T (int file_descriptor) : m_file_descriptor (file_descriptor), m_pointer (0)
{
}

T::T (int file_descriptor, off_t initial_position)
:	m_file_descriptor (file_descriptor), m_pointer (initial_position)
{
}
