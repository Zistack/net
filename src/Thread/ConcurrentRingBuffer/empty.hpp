template <class Element>
bool
T<Element>::empty () const
{
	return this->head.load () == this->tail.load ();
}
