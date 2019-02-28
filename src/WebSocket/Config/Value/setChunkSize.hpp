void
T::setChunkSize (uint64_t chunk_size)
{
	this->set<GetConfig::UInt::Type::T> (Spec::T::CHUNK_SIZE, chunk_size);
}
