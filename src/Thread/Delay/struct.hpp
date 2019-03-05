template <class Element>
struct T : Failure::Cancellable::T
{
	T ();

	void
	set (const Element & element);

	void
	set (Element && element);

	Element
	get ();

	void
	cancel () override;

	~T () = default;

	std::shared_ptr<std::promise<Element>> promise;
};
