template <typename Watchable, typename>
struct T : std::false_type
{
};

template <typename Watchable>
struct T
<
	Watchable,
	std::enable_if_t
	<
		std::is_convertible_v
		<
			decltype (std::declval <const Watchable> () . fileDescriptor ()),
			int
		>
	>
> : std::true_type
{
};
