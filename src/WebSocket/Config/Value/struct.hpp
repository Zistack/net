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

	void
	setCloseTimeout (std::chrono::milliseconds close_timeout);

	std::chrono::milliseconds
	getCloseTimeout () const;

	void
	setChunkSize (uint64_t chunk_size);

	uint64_t
	getChunkSize () const;

	void
	setTempFileThreshhold (uint64_t temp_file_threshhold);

	uint64_t
	getTempFileThreshhold () const;
};
