template <class Element>
void
T<Element>::push (const Element & element)
{
	std::unique_lock<decltype (this->mutex)> lock (this->mutex);

	if (this->closed) throw Failure::CancelException::T ();

	this->elements.push_back (element);

	this->condition_variable.notify_one ();
}

template <class Element>
void
T<Element>::push (Element && element)
{
	std::unique_lock<decltype (this->mutex)> lock (this->mutex);

	if (this->closed) throw Failure::CancelException::T ();

	this->elements.push_back (element);

	this->condition_variable.notify_one ();
}
