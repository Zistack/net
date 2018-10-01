template <class Element>
T<Element>::T (DelayQueue::T<Element> & delay_queue) : delay_queue (delay_queue)
{
	delay_queue.reset ();
}
