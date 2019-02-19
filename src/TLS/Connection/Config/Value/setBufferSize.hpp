void
T::setBufferSize (uint64_t buffer_size)
{
	this->set<GetConfig::UInt::Type::T> (Spec::T::BUFFER_SIZE, buffer_size);
}
