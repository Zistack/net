template <class Element>
Element
T <Element>::get ()
{
	return this -> promise -> get_future () . get ();
}
