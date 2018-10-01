template <class Element>
struct T
{
	T (DelayQueue::T<Element> & delay_queue);

	~T ();

	DelayQueue::T<Element> & delay_queue;
};
