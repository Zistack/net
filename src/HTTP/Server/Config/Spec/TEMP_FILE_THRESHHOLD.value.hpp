static const std::string TEMP_FILE_THRESHHOLD = "Temp-File-Threshhold";
static const std::string TEMP_FILE_THRESHHOLD_DESCRIPTION =
	"When the size of a request is known, request entities larger than this "
	"number of bytes ill be read into a temporary file rather than a buffer on "
	"the heap.";
static const std::optional <GetConfig::UInt::T>
TEMP_FILE_THRESHHOLD_DEFAULT (163484);