uint64_t
T::getBufferSize () const
{
	return this->get<GetConfig::UInt::Type::T> (Spec::T::BUFFER_SIZE).value ();
}
