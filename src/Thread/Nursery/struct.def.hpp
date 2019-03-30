struct T
{
	T () noexcept;

	T (Failure::ExceptionStore::T & exception_store) noexcept;

	template
	<
		typename Cancellable,
		typename Function,
		typename ... Arguments,
		typename = typename std::enable_if_t
		<
			std::is_invocable_v <Function, Arguments ...>
		>
	>
	void
	add
	(
		Cancellable & cancellable,
		Function && function,
		Arguments && ... arguments
	) noexcept;

	template
	<
		typename Function,
		typename ... Arguments,
		typename = typename std::enable_if_t
		<
			std::is_invocable_v <Function, Arguments ...>
		>
	>
	void
	add (Function && function, Arguments && ... arguments) noexcept;

	template
	<
		typename Cancellable,
		typename Function,
		typename ... Arguments,
		typename = typename std::enable_if_t
		<
			std::is_invocable_v <Function, Arguments ...>
		>
	>
	void
	add
	(
		Cancellable * cancellable,
		Function && function,
		Arguments && ... arguments
	) noexcept;

	template
	<
		typename Cancellable,
		typename Function,
		typename ... Arguments,
		typename = typename std::enable_if_t
		<
			std::is_invocable_v <Function, Arguments ...>
		>
	>
	void
	run
	(
		Cancellable & cancellable,
		Function && function,
		Arguments && ... arguments
	) noexcept;

	template
	<
		typename Function,
		typename ... Arguments,
		typename = typename std::enable_if_t
		<
			std::is_invocable_v <Function, Arguments ...>
		>
	>
	void
	run (Function && function, Arguments && ... arguments) noexcept;

	template
	<
		typename Cancellable,
		typename Function,
		typename ... Arguments,
		typename = typename std::enable_if_t
		<
			std::is_invocable_v <Function, Arguments ...>
		>
	>
	void
	run
	(
		Cancellable * cancellable,
		Function && function,
		Arguments && ... arguments
	) noexcept;

	template
	<
		typename Cancellable,
		typename Function,
		typename ... Arguments,
		typename = typename std::enable_if_t
		<
			std::is_invocable_v <Function, Arguments ...>
		>
	>
	void
	call
	(
		Cancellable & cancellable,
		Function && function,
		Arguments && ... arguments
	);

	template
	<
		typename Function,
		typename ... Arguments,
		typename = typename std::enable_if_t
		<
			std::is_invocable_v <Function, Arguments ...>
		>
	>
	void
	call (Function && function, Arguments && ... arguments);

	template
	<
		typename Cancellable,
		typename Function,
		typename ... Arguments,
		typename = typename std::enable_if_t
		<
			std::is_invocable_v <Function, Arguments ...>
		>
	>
	void
	call
	(
		Cancellable * cancellable,
		Function && function,
		Arguments && ... arguments
	);

	void
	cancel () noexcept;

	~T () noexcept (false);

	private:
	template <typename Cancellable, typename Function, typename ... Arguments>
	bool
	start
	(
		Cancellable * cancellable,
		Function && function,
		Arguments && ... arguments
	) noexcept;

	template <typename Function, typename ... Arguments>
	void
	execute (Function && function, Arguments && ... arguments) noexcept;

	void
	finish () noexcept;

	void
	join ();

	std::mutex m;
	std::condition_variable c;
	bool cancelled;

	std::unordered_map <std::thread::id, Thread::T> threads;

	std::unique_ptr <Failure::ExceptionStore::T> internal_store;
	Failure::ExceptionStore::T & exception_store;

	static_assert (Failure::TypeTraits::IsCancellable::T <T>::value);
};
