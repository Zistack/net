template <typename Response, typename Interface>
void
T <Response, Interface>::cancel ()
{
	this -> response_queue . cancel ();
}
