template <class Element>
struct T
{
	T (size_t size);

	void
	push (Element && element);

	Element
	pop ();

	bool
	empty () const;

	bool
	full () const;

	~T () = default;

	private:
	size_t
	successor (size_t i) const;

	const size_t size;

	std::atomic<size_t> head;
	std::mutex head_mutex;

	std::atomic<size_t> tail;
	std::mutex tail_mutex;

	std::unique_ptr<Element[]> elements;
};
