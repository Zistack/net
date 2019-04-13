template
<
	typename Argument,
	typename RemainingArgumentPack,
	template <typename ...> typename ResultPackContainer = std::tuple
>
using T = typename Implementation::T
<
	Argument,
	RemainingArgumentPack,
	ResultPackContainer
>::Type;
