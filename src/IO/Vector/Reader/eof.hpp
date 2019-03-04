bool
T::eof () const
{
	return this->pointer == this->vector.size ();
}
