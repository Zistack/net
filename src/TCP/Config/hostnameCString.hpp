const char *
T::hostnameCString () const
{
	if (this->hostname.empty ())
		return nullptr;
	else
		return this->hostname.data ();
}
