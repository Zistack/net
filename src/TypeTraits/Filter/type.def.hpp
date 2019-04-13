template
<
	typename ArgumentPack,
	template <typename> typename Predicate,
	template <typename ...> typename ResultPackContainer = std::tuple
>
using T = typename Implementation::T
<
	ArgumentPack,
	Predicate,
	ResultPackContainer
>::Type;
