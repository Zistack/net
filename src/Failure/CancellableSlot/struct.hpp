template <typename Cancellable>
struct T
{
	T ();

	void
	cancel ();

	~T () = default;

	private:
	void
	open (Cancellable & cancellable);

	void
	close ();

	std::atomic<bool> cancelled;
	std::atomic<Cancellable *> cancellable;

	friend struct Scope::T<T>;
};
