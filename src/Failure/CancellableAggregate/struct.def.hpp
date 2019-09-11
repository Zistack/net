template <typename ... Cancellables>
struct T
{
	T (Cancellables ... cancellables);

	void
	cancel ();

	~T () = default;

private:

	template <std::size_t ... N>
	void
	cancel (std::index_sequence <N ...> indices);

	std::tuple <Cancellables ...> m_cancellables;
};

template <typename ... Cancellables>
T (Cancellables && ... cancellables) -> T <Cancellables ...>;

static_assert
(
	TypeTraits::IsCancellable::T <T <TypeTraits::Cancellable::T>>::value
);
