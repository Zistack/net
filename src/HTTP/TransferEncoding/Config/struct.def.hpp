struct T : Spec::T
{
	using InterfaceType = T;

	using Spec::T::T;

	void
	setTransferEncoding (const NullableString::T & transfer_encoding);

	NullableString::T
	getTransferEncoding () const;

	void
	setChunkSize (uint64_t chunk_size);

	uint64_t
	getChunkSize () const;
};
