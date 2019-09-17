template <typename Cancellable>
struct T : Base::T
{
	template <typename Function, typename ... Arguments>
	T
	(
		Cancellable && cancellable,
		Function && function,
		Arguments && ... arguments
	);

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

	void
	cancel ();

	~T () = default;

private:

	std::thread m_thread;
};

