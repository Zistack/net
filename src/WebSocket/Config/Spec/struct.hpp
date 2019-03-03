struct T
{
	static constexpr const char * const INPUT_TIMEOUT = "Input-Timeout";
	static constexpr const char * const OUTPUT_TIMEOUT = "Output-Timeout";
	static constexpr const char * const CLOSE_TIMEOUT = "Close-Timeout";
	static constexpr const char * const CHUNK_SIZE = "Chunk-Size";
	static constexpr const char * const TEMP_FILE_THRESHHOLD =
	    "Temp-File-Threshhold";

	static const GetConfig::Section::Spec::T value;
};
