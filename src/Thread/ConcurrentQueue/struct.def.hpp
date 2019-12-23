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

	std::mutex m_mutex;
	std::condition_variable m_condition_variable;
	bool m_closed;
	std::list <Element> m_elements;

	friend struct Scope::T <T>;
};

static_assert
(
	Failure::IsCancellable::T <T <std::monostate>>::value
);
