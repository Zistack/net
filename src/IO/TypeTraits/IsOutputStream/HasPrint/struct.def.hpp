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
		std::is_invocable_r_v
		<
			void,
			decltype
			(
				& std::remove_cv_t
				<
					std::remove_reference_t <OutputStream>
				>::print
			),
			std::remove_cv_t <std::remove_reference_t <OutputStream>> *,
			const std::string &
		>
	>
> : std::true_type
{
};
