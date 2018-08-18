Protocol::T *
T::make ()
{
	return new Protocol::T (
	    this->protocol_factory.make (), this->context, this->timeout_ns);
}
