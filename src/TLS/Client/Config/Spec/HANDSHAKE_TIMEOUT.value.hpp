static const std::string HANDSHAKE_TIMEOUT = "Handshake-Timeout";
static const std::string HANDSHAKE_TIMEOUT_DESCRIPTION =
	"Timeout for performing the opening and closing handshakes.";
static const std::optional <GetConfig::Duration::T::Value> HANDSHAKE_TIMEOUT_DEFAULT
(
	std::chrono::milliseconds (5000)
);
