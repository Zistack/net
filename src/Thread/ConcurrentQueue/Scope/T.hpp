template <class Element>
T<Element>::T (ConcurrentQueue::T<Element> & concurrent_queue) :
    concurrent_queue (concurrent_queue)
{
	concurrent_queue.open ();
}
