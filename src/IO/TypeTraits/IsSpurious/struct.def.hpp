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
		std::is_invocable_r_v
		<
			bool,
			decltype
			(
				& std::remove_cv_t
				<
					std::remove_reference_t <Spurious>
				>::spurious
			),
			std::remove_cv_t <std::remove_reference_t <Spurious>> *
		>
	>
> : std::true_type
{
};
