template <typename Rule>
auto
parseFile
(
	const std::string & filename,
	std::chrono::milliseconds timeout,
	Rule && rule
);
