struct T
{
	T (bool optional,
	    const std::unique_ptr<MemberType::T> & type,
	    const std::unique_ptr<MemberValue::T> & value);

	T (const T & other);

	T (T && other) = default;

	T &
	operator= (const T & other);

	T &
	operator= (T && other) = default;

	~T () = default;

	bool optional;
	std::unique_ptr<MemberType::T> type;
	std::unique_ptr<MemberValue::T> value;
};
