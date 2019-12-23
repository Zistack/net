template <typename Buffered, typename>
struct T : std::false_type
{
};

template <typename Buffered>
struct T
<
	Buffered,
	std::enable_if_t
	<
		std::is_convertible_v
		<
			decltype (std::declval <Buffered> () . flush ()),
			void
		>
	>
>
:	std::true_type
{
};
