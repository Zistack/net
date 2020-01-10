template <typename Element>
void
T <Element>::push (const Element & element)
{
	std::unique_lock lock (this -> m_mutex);

	if (this -> m_closed) throw Failure::EndOfResource::T ();

	this -> m_elements . push_back (element);

	this -> m_condition_variable . notify_one ();
}

template <typename Element>
void
T <Element>::push (Element && element)
{
	std::unique_lock lock (this -> m_mutex);

	if (this -> m_closed) throw Failure::EndOfResource::T ();

	this -> m_elements . push_back (std::move (element));

	this -> m_condition_variable . notify_one ();
}

template <typename Element>
template <typename NonEmptyEvent>
void
T <Element>::push (const Element & element, NonEmptyEvent && nonEmptyEvent)
{
	std::unique_lock lock (this -> m_mutex);

	if (this -> m_closed) throw Failure::EndOfResource::T ();

	if (this -> m_elements . empty ()) nonEmptyEvent ();

	this -> m_elements . push_back (element);

	this -> m_condition_variable . notify_one ();
}

template <typename Element>
template <typename NonEmptyEvent>
void
T <Element>::push (Element && element, NonEmptyEvent && nonEmptyEvent)
{
	std::unique_lock lock (this -> m_mutex);

	if (this -> m_closed) throw Failure::EndOfResource::T ();

	if (this -> m_elements . empty ()) nonEmptyEvent ();

	this -> m_elements . push_back (std::move (element));

	this -> m_condition_variable . notify_one ();
}
