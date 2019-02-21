struct T
{
	static constexpr const char * const INPUT_TIMEOUT = "Input-Timeout";
	static constexpr const char * const OUTPUT_TIMEOUT = "Output-Timeout";
	static constexpr const char * const ROUND_TRIP_TIMEOUT =
	    "Round-Trip-Timeout";

	static const GetConfig::Section::Spec::T value;
};
