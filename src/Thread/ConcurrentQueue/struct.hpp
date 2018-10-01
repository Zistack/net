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

	void
	cancel ();

	void
	reset ();

	~T () = default;

	bool closed;
	std::mutex mutex;
	std::condition_variable condition_variable;
	std::list<Element> elements;
};
