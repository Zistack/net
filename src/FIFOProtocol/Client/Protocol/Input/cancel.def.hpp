template <typename Response, typename Interface>
void
T <Response, Interface>::cancel ()
{
	this -> input_shutdown_signal . cancel ();
	this -> response_queue . cancel ();
}
