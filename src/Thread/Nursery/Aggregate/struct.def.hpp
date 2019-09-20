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

	void
	cancel ();

	~T ();

private:

	template
	<
		template <typename ...> typename ArgumentPackContainer,
		typename Cancellable,
		typename Function,
		typename ... Arguments,
		std::size_t ... index
	>
	static auto
	wrapFunctionImplementation
	(
		T * aggregate,
		ArgumentPackContainer
		<
			Cancellable,
			Function,
			Arguments ...
		> & arguments,
		std::index_sequence <index ...>
	);

	template
	<
		template <typename ...> typename ArgumentPackContainer,
		typename Cancellable,
		typename Function,
		typename ... Arguments
	>
	static auto
	wrapFunction
	(
		T * aggregate,
		ArgumentPackContainer
		<
			Cancellable,
			Function,
			Arguments ...
		> & arguments
	);

	template
	<
		template <typename ...> typename ArgumentPackContainer,
		typename Cancellable,
		typename Function,
		typename ... Arguments
	>
	static auto
	wrapFunction
	(
		T * aggregate,
		ArgumentPackContainer
		<
			Cancellable,
			Function,
			Arguments ...
		> && arguments
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
