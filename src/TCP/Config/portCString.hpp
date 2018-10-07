const char *
T::portCString () const
{
	if (this->port.empty ())
		return nullptr;
	else
		return this->port.data ();
}
