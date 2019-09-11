T::T (const Data::T & vector) : m_vector (vector), m_pointer (0)
{
}

T::T (const Data::T & vector, Size::T initial_position)
:	m_vector (vector), m_pointer (initial_position)
{
}
