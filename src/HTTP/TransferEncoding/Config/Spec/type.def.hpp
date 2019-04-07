using T = GetConfig::Section::T
<
	GetConfig::Member::T
	<
		GetConfig::String::T,
		true,
		TRANSFER_ENCODING,
		TRANSFER_ENCODING_DESCRIPTION
	>,
	GetConfig::Member::T
	<
		GetConfig::UInt::T,
		false,
		CHUNK_SIZE,
		CHUNK_SIZE_DESCRIPTION,
		CHUNK_SIZE_DEFAULT
	>
>;
