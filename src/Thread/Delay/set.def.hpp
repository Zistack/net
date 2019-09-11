template <class Element>
void
T <Element>::set (const Element & element)
{
	try
	{
		this -> m_promise -> set_value (element);
	}
	catch (std::future_error)
	{
	}
}

template <class Element>
void
T <Element>::set (Element && element)
{
	try
	{
		this -> m_promise -> set_value (std::move (element));
	}
	catch (std::future_error)
	{
	}
}
