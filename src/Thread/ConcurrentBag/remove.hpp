template <class Element>
void
T<Element>::remove (Element element)
{
	std::unique_lock<decltype (this->m)> lock (this->m);
	this->elements.erase (element);
}
