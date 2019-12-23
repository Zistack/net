template <typename OutputStream, typename>
struct T : std::false_type
{
};

template <typename OutputStream>
struct T
<
	OutputStream,
	std::enable_if_t
	<
		std::is_convertible_v
		<
			decltype
			(
				std::declval <OutputStream> () . put (std::declval <char> ())
			),
			void
		>
	>
>
:	std::true_type
{
};
