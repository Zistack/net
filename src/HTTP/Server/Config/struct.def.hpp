struct T : Spec::T
{
	using InterfaceType = T;

	using Spec::T::T;

	void
	setInputTimeout (std::chrono::milliseconds input_timeout);

	std::chrono::milliseconds
	getInputTimeout () const;

	void
	setOutputTimeout (std::chrono::milliseconds output_timeout);

	std::chrono::milliseconds
	getOutputTimeout () const;

	void
	setTransferEncodingConfig
	(
		const TransferEncoding::Config::T & transfer_encoding_config
	);

	TransferEncoding::Config::T
	getTransferEncodingConfig () const;

	void
	setTempFileThreshhold (uint64_t temp_file_threshhold);

	uint64_t
	getTempFileThreshhold () const;
};
