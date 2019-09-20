template
<
	template <typename ...> typename ResultPackContainser = std::tuple,
	typename Function,
	template <typename ...> typename ArgumentPackContainer,
	typename ... Arguments
>
auto
map
(
	Function && function,
	ArgumentPackContainer <Arguments ...> & arguments
);

template
<
	template <typename ...> typename ResultPackContainser = std::tuple,
	typename Function,
	template <typename ...> typename ArgumentPackContainer,
	typename ... Arguments
>
auto
map
(
	Function && function,
	ArgumentPackContainer <Arguments ...> && arguments
);
