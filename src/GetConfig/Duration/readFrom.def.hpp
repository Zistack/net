template <typename InputStream>
T::Value
T::readFrom (InputStream && input_stream)
{
	uint64_t count = IO::Rule::getUInt (std::forward <InputStream> (input_stream));

	Util::skipWhitespace (std::forward <InputStream> (input_stream));

	std::string unit = Rule::getUnit (std::forward <InputStream> (input_stream));

	if (unit == "ns") return std::chrono::nanoseconds (count);
	if (unit == "us") return std::chrono::microseconds (count);
	if (unit == "ms") return std::chrono::milliseconds (count);
	if (unit == "s") return std::chrono::seconds (count);
	if (unit == "min") return std::chrono::minutes (count);
	if (unit == "h") return std::chrono::hours (count);

	throw Failure::SyntaxError::T ("Unrecognized unit: '" + unit + "'\n");
}
