struct T
{
	static constexpr const char * const FIFO_PROTOCOL_CONFIG = "Timeouts";
	static constexpr const char * const TRANSFER_ENCODING_CONFIG = "Encoding";
	static constexpr const char * const TEMP_FILE_THRESHHOLD =
	    "Temp-File-Threshhold";

	static const GetConfig::Section::Spec::T value;
};
