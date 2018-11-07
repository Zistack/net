template <class Element>
struct T
{
	T ();

	void
	push (const Element & element);

	void
	push (Element && element);

	Element
	pop ();

	Optional::T<Element>
	tryPop ();

	void
	open ();

	void
	close ();

	~T () = default;

	private:
	std::mutex m;
	std::condition_variable c;
	bool closed;
	std::list<Element> elements;
};
