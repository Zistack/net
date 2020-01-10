template <typename Interface>
template <typename ProxyInterface, typename>
void
T <Interface>::queueIdle ()
{
	this -> interface () . queueIdle ();
}
