template <class Function, class ... Arguments>
void
T::execute (Function && function, Arguments && ... arguments) noexcept
{
	bool first_fail = this -> m_exception_store . tryStore
	(
		std::forward <Function> (function),
		std::forward <Arguments> (arguments) ...
	);
	this -> finish ();
	if (first_fail) this -> cancel ();
}
