T::T (Type::T message_type) : m_message_type (message_type)
{
}

T::T (Type::T message_type, size_t message_size, uint64_t temp_file_threshhold)
:	m_message_type (message_type),
	HTTP::Entity::T (message_size, temp_file_threshhold)
{
}
