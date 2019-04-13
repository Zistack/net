template
<
	typename Argument,
	template <typename ...> typename RemainingArgumentPackContainer,
	typename ... RemainingArguments,
	template <typename ...> typename ResultPackContainer
>
struct T
<
	Argument,
	RemainingArgumentPackContainer <RemainingArguments ...>,
	ResultPackContainer
>
{
	using Type = ResultPackContainer <Argument, RemainingArguments ...>;
};
