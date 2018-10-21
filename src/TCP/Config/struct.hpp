struct T
{
	T (const NullableString::T & hostname, const NullableString::T & port);

	T (JSON::Value::T * config_value);

	T () = default;

	~T () = default;

	NullableString::T hostname;
	NullableString::T port;
};
