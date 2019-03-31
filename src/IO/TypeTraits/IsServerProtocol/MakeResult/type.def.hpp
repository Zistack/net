template <typename ServerProtocol>
using T = std::invoke_result_t
<
	decltype
	(
		& std::remove_cv_t <std::remove_reference_t <ServerProtocol>>::make
	),
	std::remove_cv_t <std::remove_reference_t <ServerProtocol>> *
>;
