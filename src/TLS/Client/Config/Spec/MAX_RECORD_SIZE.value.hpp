static const std::string MAX_RECORD_SIZE = "Max-Record-Size";
static const std::string MAX_RECORD_SIZE_DESCRIPTION =
	"The max size of the TLS records to send over this connection, in bytes.  "
	"The client will attempt to negotiate this to be the max size going in "
	"both directions, though this may fail.  The client will respect this "
	"setting regardless of whether or not negotiation with the server "
	"succeeds.  The default value is 1440 bytes, which is the largest record "
	"that will fit within a single TCP packet that respects the ethernet MTU.";
static const std::optional <GetConfig::UInt::T::Value> MAX_RECORD_SIZE_DEFAULT
(
	1440
);
