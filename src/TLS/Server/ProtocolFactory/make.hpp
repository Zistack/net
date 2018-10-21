Connection::Protocol::T *
T::make ()
{
	return new Connection::Protocol::T (
	    this->protocol_factory->make (), this->timeout, this->context);
}
