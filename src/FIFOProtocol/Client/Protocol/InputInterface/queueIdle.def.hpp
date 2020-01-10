template <typename Interface, typename Response>
template <typename ProxyInterface, typename>
void
T <Interface, Response>::queueIdle ()
{
	this -> interface () . queueIdle ();
}
