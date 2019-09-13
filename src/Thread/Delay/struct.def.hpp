template <typename Element>
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

private:

	std::shared_ptr <std::promise <Element>> m_promise;
};

static_assert (Failure::TypeTraits::IsCancellable::T <T <int>>::value);
