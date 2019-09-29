template <typename Cancellable>
struct T : Base::T
{
	T (Cancellable cancellable);

	T (T && other);

	T &
	operator = (T && other);

	void
	cancel ();

	~T () = default;

private:

	Cancellable m_cancellable;
};

template <>
struct T <std::nullptr_t> : Base::T
{
	T (std::nullptr_t);

	T (T && other) = default;

	T &
	operator = (T && other) = default;

	void
	cancel ();

	~T () = default;
};

template <typename Cancellable, typename Function, typename ... Arguments>
T
(
	Cancellable && cancellable,
	Function && function,
	Arguments && ... arguments
) ->
T <Cancellable>;
