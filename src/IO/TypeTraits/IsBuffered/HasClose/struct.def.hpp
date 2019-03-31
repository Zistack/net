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
		std::is_invocable_r_v
		<
			void,
			decltype
			(
				& std::remove_cv_t <std::remove_reference_t <Buffered>>::close
			),
			std::remove_cv_t <std::remove_reference_t <Buffered>> *
		>
	>
> : std::true_type
{
};
