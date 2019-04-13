template
<
	template <typename ...> typename ArgumentPackContainer,
	typename Argument,
	typename ... RemainingArguments,
	template <typename> typename Predicate,
	template <typename ...> typename ResultPackContainer
>
struct T
<
	ArgumentPackContainer <Argument, RemainingArguments ...>,
	Predicate,
	ResultPackContainer
>
{
	using RemainingResultPack = typename T
	<
		ArgumentPackContainer <RemainingArguments ...>,
		Predicate,
		ResultPackContainer
	>::Type;

	using Type = std::conditional_t
	<
		Predicate <Argument>::value,
		Cons::T <Argument, RemainingResultPack, ResultPackContainer>,
		RemainingResultPack
	>;
};
