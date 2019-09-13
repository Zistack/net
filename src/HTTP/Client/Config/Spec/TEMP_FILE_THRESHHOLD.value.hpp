static const std::string TEMP_FILE_THRESHHOLD = "Temp-File-Threshhold";
static const std::string TEMP_FILE_THRESHHOLD_DESCRIPTION =
	"When the size of the response is known, response entities larger than "
	"this number of bytes ill be read into a temporary file rather than a "
	"buffer on the heap.";
static const std::optional <GetConfig::UInt::T::Value>
TEMP_FILE_THRESHHOLD_DEFAULT
(
	163484
);
