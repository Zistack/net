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
		std::is_invocable_r_v
		<
			void,
			decltype
			(
				& std::remove_cv_t <std::remove_reference_t <Clearable>>::clear
			),
			std::remove_cv_t <std::remove_reference_t <Clearable>> *
		>
	>
> : std::true_type
{
};
