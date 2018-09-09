template <class Element>
Element
T<Element>::pop ()
{
	std::unique_lock<decltype (this->mutex)> lock (this->mutex);

	while (true)
	{
		if (!this->elements.empty ())
		{
			Element element = elements.front ();
			this->elements.pop_front ();
			return element;
		}

		if (this->closed) throw End::T ();

		this->condition_variable.wait (lock);
	}
}
