static const std::string TRANSFER_ENCODING_CONFIG = "Encoding";
static const std::string TRANSFER_ENCODING_CONFIG_DESCRIPTION =
	"Transfer encoding configuration to use when sending requests to the "
	"server.";
static const std::optional <TransferEncoding::Config::T>
TRANSFER_ENCODING_CONFIG_DEFAULT
(
	std::in_place_type <TransferEncoding::Config::T>
);
