struct T
{
	T (const std::string & field_value);

	operator size_t () const;

	~T () = default;

	size_t content_length;
};
