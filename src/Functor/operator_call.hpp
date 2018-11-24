template <auto f>
template <class... Arguments, typename>
typename std::invoke_result<decltype (f), Arguments...>::type
T<f>::operator() (Arguments &&... arguments)
{
	return f (std::forward<Arguments> (arguments)...);
}
