template <typename Element>
std::optional <Element>
T <Element>::tryPop ()
{
	std::unique_lock lock (this -> m_mutex);

	if (! this -> m_elements . empty ())
	{
		Element element = std::move (this -> m_elements . front ());
		this -> m_elements . pop_front ();
		return element;
	}
	else return {};
}

template <typename Element>
template <typename EmptyEvent>
std::optional <Element>
T <Element>::tryPop (EmptyEvent && emptyEvent)
{
	std::unique_lock lock (this -> m_mutex);

	if (! this -> m_elements . empty ())
	{
		Element element = std::move (this -> m_elements . front ());
		this -> m_elements . pop_front ();
		if (this -> m_elements . empty ()) emptyEvent ();
		return element;
	}
	else return {};
}
