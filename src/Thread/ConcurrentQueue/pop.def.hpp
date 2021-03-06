template <typename Element>
Element
T <Element>::pop ()
{
	std::unique_lock lock (this -> m_mutex);

	while (true)
	{
		if (! this -> m_elements . empty ())
		{
			Element element = std::move (this -> m_elements . front ());
			this -> m_elements . pop_front ();
			return element;
		}

		if (this -> m_closed) throw Failure::EndOfResource::T ();

		this -> m_condition_variable . wait (lock);
	}
}

template <typename Element>
template <typename EmptyEvent>
Element
T <Element>::pop (EmptyEvent && emptyEvent)
{
	std::unique_lock lock (this -> m_mutex);

	while (true)
	{
		if (! this -> m_elements . empty ())
		{
			Element element = std::move (this -> m_elements . front ());
			this -> m_elements . pop_front ();
			if (this -> m_elements . empty ()) emptyEvent ();
			return element;
		}

		if (this -> m_closed) throw Failure::EndOfResource::T ();

		this -> m_condition_variable . wait (lock);
	}
}
