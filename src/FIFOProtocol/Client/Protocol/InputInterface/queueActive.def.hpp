template <typename Interface, typename Response>
template <typename ProxyInterface, typename>
void
T <Interface, Response>::queueActive ()
{
	this -> interface () . queueActive ();
}
