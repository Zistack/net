template <class Element>
struct T
{
	T () = default;

	void
	insert (Element element);

	void
	remove (Element element);

	void
	map (std::function<void(Element element)> f);

	~T () = default;

	std::mutex m;
	std::unordered_set<Element> elements;
};
