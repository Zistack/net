template <class Element>
struct T
{
	T (ConcurrentQueue::T<Element> & concurrent_queue);
	T (const T & other) = delete;

	~T ();

	ConcurrentQueue::T<Element> & concurrent_queue;
};
