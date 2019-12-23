template <typename Cancellable, typename>
struct T : std::false_type
{
};

template <typename Cancellable>
struct T
<
	Cancellable,
	std::enable_if_t
	<
		std::is_convertible_v
		<
			decltype (std::declval <Cancellable> () . cancel ()),
			void
		>
	>
> : std::true_type
{
};
