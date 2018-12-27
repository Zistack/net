struct T
{
	T ();

	T (JSON::Value::T * config_value);

	~T () = default;

	static const NullableString::T DEFAULT_TRANSFER_ENCODING;
	NullableString::T transfer_encoding;

	static const uint64_t DEFAULT_CHUNK_SIZE = 1024;
	uint64_t chunk_size;
};
