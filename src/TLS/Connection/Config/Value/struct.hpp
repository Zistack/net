struct T : GetConfig::Section::Value::T<T, Spec::T::value>
{
	using GetConfig::Section::Value::T<T, Spec::T::value>::T;

	void
	setTimeout (uint64_t timeout);

	uint64_t
	getTimeout () const;

	void
	setBufferSize (uint64_t buffer_size);

	uint64_t
	getBufferSize () const;
};
