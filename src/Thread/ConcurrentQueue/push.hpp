template <class Element>
void
T<Element>::push (Element element)
{
	std::unique_lock<decltype (this->mutex)> lock (this->mutex);

	this->elements.push_back (element);

	this->condition_variable.notify_one ();
}
