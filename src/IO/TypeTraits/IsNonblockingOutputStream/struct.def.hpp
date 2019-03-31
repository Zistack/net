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
		std::is_invocable_r_v
		<
			size_t,
			decltype
			(
				& std::remove_cv_t
				<
					std::remove_reference_t <NonblockingOutputStream>
				>::write
			),
			std::remove_cv_t
			<
				std::remove_reference_t <NonblockingOutputStream>
			> *,
			const char *,
			size_t
		>
	>
> : std::true_type
{
};
