T::T () : m_file_descriptor (-1)
{
}

T::T (int file_descriptor) : m_file_descriptor (file_descriptor)
{
}

T::T (T && other) : m_file_descriptor (other . m_file_descriptor)
{
	other . m_file_descriptor = -1;
}
