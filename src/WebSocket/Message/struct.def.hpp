struct T : HTTP::Entity::T
{
	T (Type::T message_type);

	T
	(
		Type::T message_type,
		uint64_t message_size,
		uint64_t temp_file_threshhold
	);

	T (T && other) = default;

	T &
	operator = (T && other) = default;

	Type::T
	type () const;

	~T () = default;

private:

	Type::T m_message_type;
};
