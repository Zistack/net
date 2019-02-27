struct T : GetConfig::Section::Value::T<T, Spec::T::value>
{
	using GetConfig::Section::Value::T<T, Spec::T::value>::T;

	void
	setTransferEncoding (const NullableString::T & transfer_encoding);

	NullableString::T
	getTransferEncoding () const;

	void
	setChunkSize (uint64_t chunk_size);

	uint64_t
	getChunkSize () const;
};
