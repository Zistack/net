template <typename Element>
struct T
{
	T ();

	void
	push (const Element & element);

	void
	push (Element && element);

	Element
	pop ();

	std::optional <Element>
	tryPop ();

	void
	cancel ();

	~T () = default;

	private:
	void
	open ();

	void
	close ();

	void
	flush ();

	std::mutex m;
	std::condition_variable c;
	bool closed;
	std::list <Element> elements;

	friend struct Scope::T <T>;

	static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
};
