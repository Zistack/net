void
T::event ()
{
	const std::string message_prefix = "TLS::Client::event\n";

	try
	{
		this->adapter->event ();
	}
	catch (Failure::Throwable::T & e)
	{
		throw e.set (message_prefix + e.what ());
	}
}
