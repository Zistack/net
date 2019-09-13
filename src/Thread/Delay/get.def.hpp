template <typename Element>
Element
T <Element>::get ()
{
	return this -> m_promise -> get_future () . get ();
}
