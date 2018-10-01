template <class Element>
struct T
{
	T () = default;

	Delay::T<Element>
	push ();

	Delay::T<Element>
	pop ();

	void
	cancel ();

	void
	reset ();

	~T () = default;

	Thread::ConcurrentQueue::T<Delay::T<Element>> queue;
};
