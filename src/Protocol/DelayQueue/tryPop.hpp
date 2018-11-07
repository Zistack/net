template <class Element>
Optional::T<Delay::T<Element>>
T<Element>::tryPop ()
{
	return this->queue.tryPop ();
}
