template <typename Interface, typename>
struct T : std::false_type
{
};

template <typename Interface>
struct T
<
	Interface,
	std::enable_if_t
	<
		std::is_convertible_v
		<
			decltype (std::declval <Interface> () . queueActive ()),
			void
		>
	>
>
:	std::true_type
{
};
