template <class Element>
void
T<Element>::push (const Element & element)
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	if (this->closed) throw Failure::EndOfResource::T ();

	this->elements.push_back (element);

	this->c.notify_one ();
}

template <class Element>
void
T<Element>::push (Element && element)
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	if (this->closed) throw Failure::EndOfResource::T ();

	this->elements.push_back (std::move (element));

	this->c.notify_one ();
}
