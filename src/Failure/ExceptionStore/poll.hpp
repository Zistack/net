void
poll ()
{
	std::string * exception_message = std::atomic_exchange (& this -> exception_message, NULL);

	if (exception_message) throw Error::T (exception_message);
}
