template <typename Cancellable>
struct T
{
	T (size_t size);

	void
	add (Cancellable & cancellable);

	void
	cancel ();

	~T () = default;

private:

	std::unique_ptr <Cancellable * []> m_cancellables;
	size_t m_next;
};

static_assert (IsCancellable::T <T <DummyCancellable::T>>::value);
