const GetConfig::UInt::T::Value &
T::chunkSize () const
{
	return this -> value <Spec::CHUNK_SIZE> ();
}

GetConfig::UInt::T::Value &
T::chunkSize ()
{
	return this -> value <Spec::CHUNK_SIZE> ();
}
