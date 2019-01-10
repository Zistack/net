template <class Element>
bool
T<Element>::full () const
{
	return this->successor (this->tail.load ()) == this->head.load ();
}
