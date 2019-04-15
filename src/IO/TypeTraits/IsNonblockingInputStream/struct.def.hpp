template <typename NonblockingInputStream, typename>
struct T : std::false_type
{
};

template <typename NonblockingInputStream>
struct T
<
	NonblockingInputStream,
	std::enable_if_t
	<
		std::is_convertible_v
		<
			decltype
			(
				std::declval <NonblockingInputStream> () . read
				(
					std::declval <char *> (),
					std::declval <size_t> ()
				)
			),
			size_t
		>
	>
> : std::true_type
{
};
