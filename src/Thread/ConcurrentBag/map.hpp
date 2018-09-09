template <class Element>
void
T<Element>::map (std::function<void(Element element)> f)
{
	std::unique_lock<decltype (this->m)> lock (this->m);
	for (Element element : this->elements) f (element);
}
