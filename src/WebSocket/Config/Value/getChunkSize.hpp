uint64_t
T::getChunkSize () const
{
	return this->get<GetConfig::UInt::Type::T> (Spec::T::CHUNK_SIZE).value ();
}
