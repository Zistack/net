static const std::string ROUND_TRIP_TIMEOUT = "Round-Trip-Timeout";
static const std::string ROUND_TRIP_TIMEOUT_DESCRIPTION =
	"Timeout in milliseconds for completing a transaction with the server.";
static const std::optional <GetConfig::UInt::T>
ROUND_TRIP_TIMEOUT_DEFAULT (2000);