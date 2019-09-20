template <typename Cancellable>
struct T : Base::T
{
	template <typename Function, typename ... Arguments>
	T
	(
		Cancellable cancellable,
		Function && function,
		Arguments && ... arguments
	);

	T (T && other);

	T &
	operator = (T && other);

	void
	cancel ();

	~T () = default;

private:

	Cancellable m_cancellable;

	std::thread m_thread;
};

template <>
struct T <std::nullptr_t> : Base::T
{
	template <typename Function, typename ... Arguments>
	T (std::nullptr_t, Function && function, Arguments && ... arguments);

	T (T && other) = default;

	T &
	operator = (T && other) = default;

	void
	cancel ();

	~T () = default;

private:

	std::thread m_thread;
};

template <typename Cancellable, typename Function, typename ... Arguments>
T
(
	Cancellable && cancellable,
	Function && function,
	Arguments && ... arguments
) ->
T <Cancellable>;

