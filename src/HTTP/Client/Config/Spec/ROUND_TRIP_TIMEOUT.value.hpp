static const std::string ROUND_TRIP_TIMEOUT = "Round-Trip-Timeout";
static const std::string ROUND_TRIP_TIMEOUT_DESCRIPTION =
	"Timeout for completing a transaction with the server.";
static const std::optional <GetConfig::Duration::T::Value>
ROUND_TRIP_TIMEOUT_DEFAULT
(
	std::chrono::milliseconds (2000)
);
