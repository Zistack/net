template <typename Function, typename ... Arguments>
bool
T::tryStore (Function && function, Arguments && ... arguments)
{
	try
	{
		function (std::forward <Arguments> (arguments) ...);
	}
	catch (...)
	{
		return this -> store (std::current_exception ());
	}

	return false;
}
