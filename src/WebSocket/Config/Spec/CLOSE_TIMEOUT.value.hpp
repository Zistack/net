static const std::string CLOSE_TIMEOUT = "Close-Timeout";
static const std::string CLOSE_TIMEOUT_DESCRIPTION =
	"Timeout in milliseconds for recieving a close frame from the peer, once a "
	"close frame has been sent.";
static const std::optional <GetConfig::UInt::T> CLOSE_TIMEOUT_DEFAULT (2000);
