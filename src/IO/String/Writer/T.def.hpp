T::T (Data::T & string) : m_string (string), m_pointer (0)
{
}

T::T (Data::T & string, Size::T initial_position)
:	m_string (string), m_pointer (initial_position)
{
}
