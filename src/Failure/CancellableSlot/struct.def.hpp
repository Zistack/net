template <typename ... Cancellables>
struct T
{
	T ();

	void
	cancel ();

	~T () = default;

private:

	template <typename Cancellable>
	void
	open (Cancellable & cancellable);

	void
	close ();

	void
	cancelCancellable ();

	std::mutex m_mutex;

	bool m_cancelled;

	std::variant <std::nullptr_t, std::reference_wrapper <Cancellables> ...>
	m_cancellable;

	friend struct Scope::T <T>;
};

static_assert
(
	TypeTraits::IsCancellable::T <T <TypeTraits::Cancellable::T>>::value
);
