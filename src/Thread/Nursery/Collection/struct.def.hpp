template <bool use_external_store, typename Cancellable>
struct T : Base::T <use_external_store, Cancellable>
{
	using Base::T <use_external_store, Cancellable>::T;

	template <typename Function, typename ... Arguments>
	void
	add
	(
		Cancellable cancellable,
		Function && function,
		Arguments && ... arguments
	);
};

template <bool use_external_store>
struct T <use_external_store, std::nullptr_t>
:	Base::T <use_external_store, std::nullptr_t>
{
	using Base::T <use_external_store, std::nullptr_t>::T;

	template <typename Function, typename ... Arguments>
	void
	add (Function && function, Arguments && ... arguments);
};
