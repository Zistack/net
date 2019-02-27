void
T::setTempFileThreshhold (uint64_t temp_file_threshhold)
{
	this->set<GetConfig::UInt::Type::T> (
	    Spec::T::TEMP_FILE_THRESHHOLD, temp_file_threshhold);
}
