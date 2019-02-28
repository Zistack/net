const GetConfig::Section::Spec::T T::value = {
	{T::INPUT_TIMEOUT, "Timeout in milliseconds for reading a frame from the peer.", false, GetConfig::UInt::Type::T (), 1000},
	{T::OUTPUT_TIMEOUT, "Timeout in milliseconds for writing a frame to the peer.", false, GetConfig::UInt::Type::T (), 1000},
	{T::CLOSE_TIMEOUT, "Timeout in milliseconds for recieving a close frame from the peer, once a close frame has been sent.", false, GetConfig::UInt::Type::T (), 2000},
	{T::CHUNK_SIZE, "Maximum chunk size in bytes to send in a single frame.", false, GetConfig::UInt::Type::T (), 4096},
	{T::TEMP_FILE_THRESHHOLD, "Messages larger than this number of bytes will be read into a temporary file rather than a buffer on the heap.", false, GetConfig::UInt::Type::T (), 16384}
};
