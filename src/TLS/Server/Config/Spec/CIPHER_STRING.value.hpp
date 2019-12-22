static const std::string CIPHER_STRING = "Ciphers";
static const std::string CIPHER_STRING_DESCRIPTION =
	"The string describing the ciphers that may be used for TLS connections.  "
	"This string's format is defined by GnuTLS.  The default value is "
	"\"NORMAL\", which corresponds to GnuTLS's default cipher suite.";
static const std::optional <GetConfig::String::T::Value> CIPHER_STRING_DEFAULT
(
	"NORMAL"
);
