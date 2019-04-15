template <typename Protocol, typename>
struct T : std::false_type
{
};

template <typename Protocol>
struct T
<
	Protocol,
	std::enable_if_t
	<
		std::is_convertible_v
		<
			decltype (std::declval <Protocol> () . prime ()),
			void
		>
	>
> : std::true_type
{
};
