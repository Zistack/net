template <typename Protocol, typename>
struct T : std::false_type
{
};

template <typename Protocol>
struct T
<
	Protocol,
	std::enable_if_t
	<
		std::is_invocable_r_v
		<
			void,
			decltype
			(
				& std::remove_cv_t <std::remove_reference_t <Protocol>>::
					template run <InputStream::T, OutputStream::T>
			),
			std::remove_cv_t <std::remove_reference_t <Protocol>> *,
			InputStream::T,
			OutputStream::T
		>
	>
> : std::true_type
{
};
