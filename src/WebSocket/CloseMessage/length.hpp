uint64_t
T::length () const
{
	if (this->status_code == 1005) return 0;

	if (this->reason)
	{
		return sizeof (this->status_code) + this->reason.stdString ().size ();
	}

	return sizeof (this->status_code);
}
