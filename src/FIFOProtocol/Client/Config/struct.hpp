struct T
{
	T ();

	T (JSON::Value::T * config_value);

	~T () = default;

	std::chrono::milliseconds input_timeout;
	static const constexpr std::chrono::milliseconds DEFAULT_INPUT_TIMEOUT =
	    std::chrono::milliseconds (1000);

	std::chrono::milliseconds output_timeout;
	static const constexpr std::chrono::milliseconds DEFAULT_OUTPUT_TIMEOUT =
	    std::chrono::milliseconds (1000);

	std::chrono::milliseconds round_trip_timeout;
	static const constexpr std::chrono::milliseconds
	    DEFAULT_ROUND_TRIP_TIMEOUT =
	        DEFAULT_INPUT_TIMEOUT + DEFAULT_OUTPUT_TIMEOUT;
};
