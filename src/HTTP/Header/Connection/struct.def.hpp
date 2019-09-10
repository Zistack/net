struct T
{
	T (const std::string & field_value);

	~T () = default;

	std::unordered_set <std::string> options;
};
