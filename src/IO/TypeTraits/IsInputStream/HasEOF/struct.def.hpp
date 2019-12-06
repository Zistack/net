template <typename InputStream, typename>
struct T : std::false_type
{
};

template <typename InputStream>
struct T
<
	InputStream,
	std::enable_if_t
	<
		std::is_convertible_v
		<
			decltype (std::declval <InputStream> () . eof ()),
			bool
		>
	>
>
:	std::true_type
{
};
