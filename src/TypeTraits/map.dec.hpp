template
<
	typename Function,
	template <typename ...> typename ArgumentPackContainer,
	typename ... Arguments,
	template <typename ...> typename ResultPackContainser = std::tuple
>
auto
map (Function && function, ArgumentPackContainer <Arguments ...> && arguments);
