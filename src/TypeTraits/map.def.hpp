template
<
	typename Function,
	template <typename ...> typename ArgumentPackContainer,
	typename ... Arguments,
	std::size_t ... index,
	template <typename ...> typename ResultPackContainer
>
auto
map_impl
(
	Function && function,
	ArgumentPackContainer <Arguments ...> && arguments,
	std::index_sequence <index ...>
)
{
	if constexpr
	(
		Contains::V <void, decltype (function (std::declval <Arguments> ())) ...>
	)
	{
		(function (std::get <index> (arguments)), ...);
	}
	else
	{
		return ResultPackContainer
		(
			function (std::get <index> (arguments)) ...
		);
	}
}

template
<
	typename Function,
	template <typename ...> typename ArgumentPackContainer,
	typename ... Arguments,
	template <typename ...> typename ResultPackContainer
>
auto
map (Function && function, ArgumentPackContainer <Arguments ...> && arguments)
{
	return map_impl <ResultPackContainer>
	(
		std::forward <Function> (function),
		std::forward <ArgumentPackContainer <Arguments ...>> (arguments),
		std::index_sequence_for <Arguments ...> {}
	);
}
