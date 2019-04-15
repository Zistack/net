template <typename Spurious, typename>
struct T : std::false_type
{
};

template <typename Spurious>
struct T
<
	Spurious,
	std::enable_if_t
	<
		std::is_convertible_v
		<
			decltype (std::declval <Spurious> () . spurious ()),
			bool
		>
	>
> : std::true_type
{
};
