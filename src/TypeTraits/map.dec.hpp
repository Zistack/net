template
<
	template <typename ...> typename ResultPackContainser = std::tuple,
	typename Function,
	typename ArgumentPack,
	typename ... ArgumentPacks
>
auto
map
(
	Function && function,
	ArgumentPack && argument_pack,
	ArgumentPacks && ... argument_packs
);
