template <typename Interface>
template <typename ProxyInterface, typename>
void
T <Interface>::readIdle ()
{
	this -> interface () . readIdle ();
}
