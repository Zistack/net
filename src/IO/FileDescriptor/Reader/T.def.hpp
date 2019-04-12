T::T (int file_descriptor) : file_descriptor (file_descriptor), pointer (0)
{
}

T::T (int file_descriptor, off_t initial_position)
:	file_descriptor (file_descriptor), pointer (initial_position)
{
}
