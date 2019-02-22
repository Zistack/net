struct T : GetConfig::Section::Value::T<T, Spec::T::value>
{
	using GetConfig::Section::Value::T<T, Spec::T::value>::T;

	void
	setInputTimeout (std::chrono::milliseconds input_timeout);

	std::chrono::milliseconds
	getInputTimeout () const;

	void
	setOutputTimeout (std::chrono::milliseconds output_timeout);

	std::chrono::milliseconds
	getOutputTimeout () const;
};
