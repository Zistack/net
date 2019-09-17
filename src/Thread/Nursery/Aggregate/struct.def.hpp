template <bool use_external_store, typename ... Cancellables>
struct T : ExceptionStore::T <use_external_store>
{
	template <typename ... ArgumentPacks>
	T (ArgumentPacks && ... argument_packs);

	template <typename ... ArgumentPacks>
	T
	(
		Failure::ExceptionStore::T & exception_store,
		ArgumentPacks && ... argument_packs
	);

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

	std::tuple <Thread::T <Cancellables> ...> m_threads;
};

template <typename ... ArgumentPacks>
T (ArgumentPacks && ... argument_packs) ->
T <false, Cancellable::T <ArgumentPacks> ...>;

template <typename ... ArgumentPacks>
T
(
	Failure::ExceptionStore::T & exception_store,
	ArgumentPacks && ... argument_packs
) ->
T <true, Cancellable::T <ArgumentPacks> ...>;
