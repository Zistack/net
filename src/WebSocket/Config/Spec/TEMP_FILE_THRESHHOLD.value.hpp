static const std::string TEMP_FILE_THRESHHOLD = "Temp-File-Threshhold";
static const std::string TEMP_FILE_THRESHHOLD_DESCRIPTION =
	"Messages larger than this number of bytes will be read into a temporary "
	"file rather than a buffer on the heap.";
static const std::optional <GetConfig::UInt::T::Value>
TEMP_FILE_THRESHHOLD_DEFAULT
(
	16384
);
