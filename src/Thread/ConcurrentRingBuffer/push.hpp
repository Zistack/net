template <class Element>
void
T<Element>::push (Element && element)
{
	std::unique_lock<decltype (this->tail_mutex)> lock (this->tail_mutex);

	if (this->full ())
	{
		throw Failure::EndOfResource::T ();
	}

	this->elements[this->tail.load ()] = std::move (element);

	this->tail.store (this->successor (this->tail.load ()));
}
