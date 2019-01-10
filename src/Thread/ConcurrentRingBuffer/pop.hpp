template <class Element>
Element
T<Element>::pop ()
{
	std::unique_lock<decltype (this->head_mutex)> lock (this->head_mutex);

	if (this->empty ())
	{
		throw Failure::EndOfResource::T ();
	}

	Element element = std::move (this->elements[this->head.load ()]);

	this->head.store (this->successor (this->head.load ()));

	return element;
}
