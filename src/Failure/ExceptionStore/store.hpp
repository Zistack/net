void
store (std::exception e)
{
	std::string * exception_message = new std::string (e.what ());

	if (! std::atomic_compare_exchange_strong (
		& this -> exception_message, NULL, exception_message))
	{
		delete exception_message;
	}
}
