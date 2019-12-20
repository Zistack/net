T::T () : m_file_descriptor (-1)
{
}

T::T (const Config::T & config)
:	m_file_descriptor (Util::server (config . hostname (), config . port ()))
{
}

T::T (T && other) : m_file_descriptor (other . m_file_descriptor)
{
	other . m_file_descriptor = -1;
}
