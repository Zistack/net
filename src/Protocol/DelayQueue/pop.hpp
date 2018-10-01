template <class Element>
Delay::T<Element>
T<Element>::pop ()
{
	return this->queue.pop ();
}
