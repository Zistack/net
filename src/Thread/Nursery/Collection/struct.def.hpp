template <typename Cancellable>
struct T : Base::T <Cancellable>
{
	template <typename Function, typename ... Arguments>
	void
	add
	(
		Cancellable cancellable,
		Function && function,
		Arguments && ... arguments
	);
};

template <>
struct T <std::nullptr_t> : Base::T <std::nullptr_t>
{
	template <typename Function, typename ... Arguments>
	void
	add (Function && function, Arguments && ... arguments);
};
