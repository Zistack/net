template <class Lockable>
T<Lockable>::operator bool () const
{
	return this->state;
}
