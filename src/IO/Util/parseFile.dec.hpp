template <typename Rep, typename Period, typename Rule>
auto
parseFile
(
	const std::string & filename,
	std::chrono::duration <Rep, Period> timeout,
	Rule && rule
);
