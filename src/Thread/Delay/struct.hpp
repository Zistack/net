template <class Element>
struct T
{
	T ();

	void
	set (const Element & element);

	void
	set (Element && element);

	Element
	get ();

	void
	cancel ();

	~T () = default;

	std::shared_ptr<std::promise<Element>> promise;

	static_assert (Failure::TypeTraits::IsCancellable::T<T>::value);
};
