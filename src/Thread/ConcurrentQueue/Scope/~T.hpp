template <class Element>
T<Element>::~T ()
{
	this->concurrent_queue.close ();
}
