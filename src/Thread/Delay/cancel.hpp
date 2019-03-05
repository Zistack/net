template <class Element>
void
T<Element>::cancel ()
{
	try
	{
		this->promise->set_exception (
		    std::make_exception_ptr (Failure::CancelException::T ()));
	}
	catch (std::future_error)
	{
	}
}
