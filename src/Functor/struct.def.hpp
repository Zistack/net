template <auto f>
struct T
{
	template
	<
		class ... Arguments,
		typename = typename std::enable_if_t
		<
			std::is_invocable_v <decltype (f), Arguments ...>
		>
	>
	typename std::invoke_result_t <decltype (f), Arguments ...>
	operator () (Arguments && ... arguments);
};
