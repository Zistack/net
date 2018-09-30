bool
T::tryStore (std::function<void(void)> f)
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
