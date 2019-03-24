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
	std::unique_ptr <Cancellable * []> cancellables;
	size_t next;
};
