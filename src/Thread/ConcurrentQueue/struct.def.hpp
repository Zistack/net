template <typename Element>
struct T
{
	T ();

	void
	push (const Element & element);

	void
	push (Element && element);

	template <typename NonEmptyEvent>
	void
	push (const Element & element, NonEmptyEvent && nonEmptyEvent);

	template <typename NonEmptyEvent>
	void
	push (Element && element, NonEmptyEvent && nonEmptyEvent);

	Element
	pop ();

	template <typename EmptyEvent>
	Element
	pop (EmptyEvent && emptyEvent);

	std::optional <Element>
	tryPop ();

	template <typename EmptyEvent>
	std::optional <Element>
	tryPop (EmptyEvent && emptyEvent);

	void
	close ();

	void
	cancel ();

	~T () = default;

private:

	void
	open ();

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
