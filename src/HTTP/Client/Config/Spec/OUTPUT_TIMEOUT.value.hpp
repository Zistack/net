static const std::string OUTPUT_TIMEOUT = "Output-Timeout";
static const std::string OUTPUT_TIMEOUT_DESCRIPTION =
	"Timeout for writing a request to the server.";
static const std::optional <GetConfig::Duration::T::Value>
OUTPUT_TIMEOUT_DEFAULT
(
	std::chrono::milliseconds (1000)
);
