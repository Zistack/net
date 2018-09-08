template <class Element>
struct T
{
	T ();

	void
	push (Element element);

	Element
	pop ();

	void
	close ();

	~T () = default;

	bool closed;
	std::mutex mutex;
	std::condition_variable condition_variable;
	std::list<Element> elements;
};
