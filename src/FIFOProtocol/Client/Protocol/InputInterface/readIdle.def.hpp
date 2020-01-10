template <typename Interface, typename Response>
template <typename ProxyInterface, typename>
void
T <Interface, Response>::readIdle ()
{
	this -> interface () . readIdle ();
}
