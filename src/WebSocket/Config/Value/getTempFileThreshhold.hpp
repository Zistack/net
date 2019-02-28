uint64_t
T::getTempFileThreshhold () const
{
	return this->get<GetConfig::UInt::Type::T> (Spec::T::TEMP_FILE_THRESHHOLD)
	    .value ();
}
