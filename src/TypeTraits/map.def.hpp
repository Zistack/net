template
<
	size_t index,
	typename Function,
	typename ArgumentPack,
	typename ... ArgumentPacks
>
auto
map_call
(
	Function && function,
	ArgumentPack && argument_pack,
	ArgumentPacks && ... argument_packs
)
{
	return function
	(
		std::get <index> (std::forward <ArgumentPack> (argument_pack)),
		std::get <index> (std::forward <ArgumentPacks> (argument_packs)) ...
	);
}

template
<
	template <typename ...> typename ResultPackContainer,
	typename Function,
	typename ArgumentPack,
	typename ... ArgumentPacks,
	std::size_t ... index
>
auto
map_impl
(
	Function && function,
	ArgumentPack && argument_pack,
	std::index_sequence <index ...>,
	ArgumentPacks && ... argument_packs
)
{
	if constexpr
	(
		Contains::V
		<
			void,
			decltype
			(
				map_call <index>
				(
					std::forward <Function> (function),
					std::forward <ArgumentPack> (argument_pack),
					std::forward <ArgumentPacks> (argument_packs) ...
				)
			) ...
		>
	)
	{
		(
			map_call <index>
			(
				std::forward <Function> (function),
				std::forward <ArgumentPack> (argument_pack),
				std::forward <ArgumentPacks> (argument_packs) ...
			),
			...
		);
	}
	else
	{
		return ResultPackContainer
		(
			map_call <index>
			(
				std::forward <Function> (function),
				std::forward <ArgumentPack> (argument_pack),
				std::forward <ArgumentPacks> (argument_packs) ...
			) ...
		);
	}
}

template
<
	template <typename ...> typename ResultPackContainer,
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
)
{
	return map_impl <ResultPackContainer>
	(
		std::forward <Function> (function),
		std::forward <ArgumentPack> (argument_pack),
		std::make_index_sequence
		<
			std::tuple_size_v <std::remove_reference_t <ArgumentPack>>
		> {},
		std::forward <ArgumentPacks> (argument_packs) ...
	);
}

