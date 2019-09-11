T::T (const InterfaceType & value) : m_value (value) {}

template <typename InputStream>
T::T (InputStream && input_stream)
:	m_value (IO::Rule::getUInt (std::forward <InputStream> (input_stream)))
{
}
