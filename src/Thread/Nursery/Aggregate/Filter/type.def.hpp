template <typename Cancellable>
using T = std::conditional_t
<
	std::is_same_v <std::remove_reference_t <Cancellable>, std::nullptr_t> ||
		std::is_rvalue_reference_v <Cancellable>,
	std::remove_reference_t <Cancellable>,
	Cancellable
>;
