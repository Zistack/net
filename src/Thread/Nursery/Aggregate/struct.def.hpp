template <typename ... Cancellables>
struct T
{
	template <typename ... ArgumentPacks>
	T (ArgumentPacks && ... argument_packs);

	~T ();

private:

	void
	cancel ();

	template <typename Cancellable, typename Function, typename ... Arguments>
	static auto
	wrapFunction
	(
		T * aggregate,
		Cancellable && cancellable,
		Function && function,
		Arguments && ... arguments
	);

	template <typename Function, typename ... Arguments>
	static void
	wrapperFunction
	(
		T * aggretate,
		Function && function,
		Arguments && ... arguments
	);

	Failure::ExceptionStore::T m_exception_store;

	std::tuple <Thread::T <Cancellables> ...> m_threads;
};

template <typename ... ArgumentPacks>
T (ArgumentPacks && ... argument_packs) -> T <Cancellable::T <ArgumentPacks> ...>;
