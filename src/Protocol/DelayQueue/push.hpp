template <class Element>
Delay::T<Element>
T<Element>::push ()
{
	Delay::T<Element> delay;

	this->queue.push (delay);

	return delay;
}
