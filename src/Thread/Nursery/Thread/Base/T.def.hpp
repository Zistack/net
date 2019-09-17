template <typename Function, typename ... Arguments>
T::T (Function && function, Arguments && ... arguments)
:	m_thread
	(
		TypeTraits::launder <Function> (function),
		TypeTraits::launder <Arguments> (arguments) ...
	)
{
}
