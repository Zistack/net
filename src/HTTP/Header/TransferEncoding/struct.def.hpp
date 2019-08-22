struct T
{
	T (const std::string & field_value);

	~T () = default;

	std::list <Specification::T> m_specifications;
};
