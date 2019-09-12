struct T : Spec::T
{
	using InterfaceType = T;

	using Spec::T::T;

	void
	setTransferEncoding (const std::optional <std::string> & transfer_encoding);

	std::optional <std::string>
	getTransferEncoding () const;

	void
	setChunkSize (uint64_t chunk_size);

	uint64_t
	getChunkSize () const;
};
