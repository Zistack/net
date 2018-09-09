template <class Element>
void
T<Element>::insert (Element element)
{
	std::unique_lock<decltype (this->m)> lock (this->m);
	this->elements.insert (element);
}
