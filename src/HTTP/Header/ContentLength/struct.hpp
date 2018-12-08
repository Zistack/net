struct T
{
	T (const std::string & field_value);

	operator size_t () const;

	size_t content_length;
};
