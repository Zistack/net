template
<
	typename ArgumentPack,
	template <typename ...> typename TypeFunction,
	template <typename ...> typename ResultPackContainer = std::tuple
>
using T =
	typename Implementation::
		T <ArgumentPack, TypeFunction, ResultPackContainer>::
		Type;
