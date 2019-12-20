static const std::string MAX_RECORD_SIZE = "Max-Record-Size";
static const std::string MAX_RECORD_SIZE_DESCRIPTION =
	"The max size of the TLS records to send over this connection, in bytes.  "
	"Clients may attempt to negotiate a size which is different during the "
	"opening handshake.  The server will respect this setting, regardless of "
	"what the client negotiates.  The default value is 1440 bytes, which is "
	"the largest record that will fit within a single TCP packet that respects "
	"the ethernet MTU.";
static const std::optional <GetConfig::UInt::T::Value> MAX_RECORD_SIZE_DEFAULT
(
	1440
);
