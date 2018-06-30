T::~T ()
{
	std::string * exception_message = std::atomic_load (& this -> exception_message);

	if (exception_message) delete exception_message;
}
