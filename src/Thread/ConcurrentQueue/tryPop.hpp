template <class Element>
std::optional<Element>
T<Element>::tryPop ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	if (!this->elements.empty ())
	{
		Element element = std::move (elements.front ());
		this->elements.pop_front ();
		return element;
	}
	else
	{
		return {};
	}
}
