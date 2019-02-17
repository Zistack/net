struct T : GetConfig::Section::Value::T<T, Spec::T::value>
{
	T (const NullableString::T & hostname, const NullableString::T & port);

	using GetConfig::Section::Value::T<T, Spec::T::value>::T;

	NullableString::T
	getHostname () const;

	void
	setHostname (const NullableString::T & hostname);

	NullableString::T
	getPort () const;

	void
	setPort (const NullableString::T & port);
};
