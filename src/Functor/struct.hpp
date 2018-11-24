template <auto f>
struct T
{
	template <class... Arguments,
	    typename = typename std::enable_if<
	        std::is_invocable<decltype (f), Arguments...>::value>::type>
	typename std::invoke_result<decltype (f), Arguments...>::type
	operator() (Arguments &&... arguments);
};
