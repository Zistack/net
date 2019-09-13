static const std::string CLOSE_TIMEOUT = "Close-Timeout";
static const std::string CLOSE_TIMEOUT_DESCRIPTION =
	"Timeout for recieving a close frame from the peer, once a close frame has "
	"been sent.";
static const std::optional <GetConfig::Duration::T::Value> CLOSE_TIMEOUT_DEFAULT
(
	std::chrono::milliseconds (2000)
);
