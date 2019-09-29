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

	template <typename ... ArgumentPacks>
	void
	init (ArgumentPacks && ... argument_packs);

	template
	<
		template <typename ...> typename ArgumentPackContainer,
		typename Cancellable,
		typename Function,
		typename ... Arguments,
		std::size_t ... index
	>
	void
	wrapFunctionImplementation
	(
		Thread::T <Filter::T <Cancellable>> & thread,
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
	void
	wrapFunction
	(
		Thread::T <Filter::T <Cancellable>> & thread,
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
	void
	wrapFunction
	(
		Thread::T <Filter::T <Cancellable>> & thread,
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
T <false, Filter::T <std::tuple_element_t <0, ArgumentPacks>> ...>;

template <typename ... ArgumentPacks>
T
(
	Failure::ExceptionStore::T & exception_store,
	ArgumentPacks && ... argument_packs
) ->
T <true, Filter::T <std::tuple_element_t <0, ArgumentPacks>> ...>;
