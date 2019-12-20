const GetConfig::UInt::T::Value &
T::maxRecordSize () const
{
	return this -> value <Spec::MAX_RECORD_SIZE> ();
}

GetConfig::UInt::T::Value &
T::maxRecordSize ()
{
	return this -> value <Spec::MAX_RECORD_SIZE> ();
}
