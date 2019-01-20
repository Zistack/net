template <class Element>
void
T<Element>::flush ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	this->elements.clear ();
}
