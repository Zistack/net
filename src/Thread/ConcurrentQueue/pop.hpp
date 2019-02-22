template <typename Element>
Element
T<Element>::pop ()
{
	std::unique_lock<decltype (this->m)> lock (this->m);

	while (true)
	{
		if (!this->elements.empty ())
		{
			Element element = std::move (elements.front ());
			this->elements.pop_front ();
			return element;
		}

		if (this->closed) throw Failure::EndOfResource::T ();

		this->c.wait (lock);
	}
}
