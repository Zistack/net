template <typename Protocol, typename ... Arguments>
T <Protocol, Arguments...>::T (Arguments ... arguments)
:	m_arguments (std::forward <Arguments> (arguments) ...)
{
}
