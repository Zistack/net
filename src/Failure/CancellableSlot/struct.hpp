template <typename... Cancellables>
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

	std::mutex mutex;

	bool cancelled;
	std::variant<std::nullptr_t, Cancellables &...> cancellable;

	friend struct Scope::T<T>;

	static_assert (TypeTraits::IsCancellable::T<T>::value);
};
