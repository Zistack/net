template <class Callable>
bool
T::tryStore (Callable && f)
{
	try
	{
		f ();
	}
	catch (...)
	{
		return this->store (std::current_exception ());
	}

	return false;
}
