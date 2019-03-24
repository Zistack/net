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

	std::tuple <Cancellables ...> cancellables;
};

template <typename ... Cancellables>
T (Cancellables && ... cancellables) -> T <Cancellables ...>;
