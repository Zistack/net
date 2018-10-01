Protocol::T *
T::make ()
{
	return new Protocol::T (this->protocol_factory->make ());
}
