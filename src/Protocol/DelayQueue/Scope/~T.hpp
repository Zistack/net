template <class Element>
T<Element>::~T ()
{
	this->delay_queue.cancel ();
}
