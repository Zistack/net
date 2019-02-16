struct T
{
	T (bool optional,
	    const std::unique_ptr<GetConfig::Member::T> & type,
	    const std::unique_ptr<GetConfig::Member::Value::T> & value);

	T (const T & other);

	T (T && other) = default;

	T &
	operator= (const T & other);

	T &
	operator= (T && other) = default;

	~T () = default;

	bool optional;
	std::unique_ptr<GetConfig::Member::T> type;
	std::unique_ptr<GetConfig::Member::Value::T> value;
};
