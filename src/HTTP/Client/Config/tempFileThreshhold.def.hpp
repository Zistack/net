const GetConfig::UInt::T::Value &
T::tempFileThreshhold () const
{
	return this -> value <Spec::TEMP_FILE_THRESHHOLD> ();
}

GetConfig::UInt::T::Value &
T::tempFileThreshhold ()
{
	return this -> value <Spec::TEMP_FILE_THRESHHOLD> ();
}
