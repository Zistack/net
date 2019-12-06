template <typename NonblockingOutputStream, typename>
struct T : std::false_type
{
};

template <typename NonblockingOutputStream>
struct T
<
	NonblockingOutputStream,
	std::enable_if_t
	<
		std::is_convertible_v
		<
			decltype
			(
				std::declval <NonblockingOutputStream> () . write
				(
					std::declval <const char *> (),
					std::declval <size_t> ()
				)
			),
			size_t
		>
	>
>
:	std::true_type
{
};
