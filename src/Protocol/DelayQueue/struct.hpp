template <class Element>
struct T
{
	T () = default;

	void
	push (Delay::T<Element> & delay);

	Delay::T<Element>
	pop ();

	Optional::T<Delay::T<Element>>
	tryPop ();

	~T () = default;

	private:
	void
	open ();

	void
	close ();

	Thread::ConcurrentQueue::T<Delay::T<Element>> queue;

	friend Scope::T<T>;
};
