void
T::tryStore (std::function<void(void)> f)
{
	try
	{
		f ();
	}
	catch (...)
	{
		this->store (std::current_exception ());
	}
}
