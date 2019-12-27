template
<
	template <typename ...> typename ArgumentPackContainer,
	typename ... Arguments,
	template <typename ...> typename TypeFunction,
	template <typename ...> typename ResultPackContainer
>
struct T
<
	ArgumentPackContainer <Arguments ...>,
	TypeFunction,
	ResultPackContainer
>
{
	using Type = ResultPackContainer <TypeFunction <Arguments> ...>;
};
