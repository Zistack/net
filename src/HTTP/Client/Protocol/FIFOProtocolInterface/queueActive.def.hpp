template <typename Interface>
template <typename ProxyInterface, typename>
void
T <Interface>::queueActive ()
{
	this -> interface () . queueActive ();
}
