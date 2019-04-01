T::T () : file_descriptor (-1)
{
}

T::T (int file_descriptor) : file_descriptor (file_descriptor)
{
}

T::T (T && other) : file_descriptor (other . file_descriptor)
{
	other . file_descriptor = -1;
}
