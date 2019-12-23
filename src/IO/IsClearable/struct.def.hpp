template <typename Clearable, typename>
struct T : std::false_type
{
};

template <typename Clearable>
struct T
<
	Clearable,
	std::enable_if_t
	<
		std::is_convertible_v
		<
			decltype (std::declval <Clearable> () . clear ()),
			void
		>
	>
>
:	std::true_type
{
};
