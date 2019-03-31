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
		std::is_invocable_r_v
		<
			char,
			decltype
			(
				& std::remove_cv_t <std::remove_reference_t <InputStream>>::get
			),
			std::remove_cv_t <std::remove_reference_t <InputStream>> *
		>
	>
> : std::true_type
{
};
