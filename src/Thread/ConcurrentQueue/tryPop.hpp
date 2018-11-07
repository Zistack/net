template <class Element>
Optional::T<Element>
T<Element>::tryPop ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	if (!this->elements.empty ())
	{
		Element element = elements.front ();
		this->elements.pop_front ();
		return element;
	}
	else
		return {};
}
