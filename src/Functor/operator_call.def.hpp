template <auto f>
template <class ... Arguments, typename>
typename std::invoke_result_t <decltype (f), Arguments ...>
T <f>::operator () (Arguments && ... arguments)
{
	return f (std::forward <Arguments> (arguments) ...);
}
