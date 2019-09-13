static const std::string INPUT_TIMEOUT = "Input-Timeout";
static const std::string INPUT_TIMEOUT_DESCRIPTION =
	"Timeout for reading a request from a client.";
static const std::optional <GetConfig::Duration::T::Value> INPUT_TIMEOUT_DEFAULT
(
	std::chrono::milliseconds (1000)
);
