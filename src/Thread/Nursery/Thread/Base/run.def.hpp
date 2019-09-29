template <typename Function, typename ... Arguments>
void
T::run (Function && function, Arguments && ... arguments)
{
	this -> m_thread = std::thread
	(
		TypeTraits::launder <Function> (function),
		TypeTraits::launder <Arguments> (arguments) ...
	);
}
