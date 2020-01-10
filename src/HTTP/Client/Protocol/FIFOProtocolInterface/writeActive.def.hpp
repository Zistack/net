template <typename Interface>
template <typename ProxyInterface, typename>
void
T <Interface>::writeActive ()
{
	this -> interface () . writeActive ();
}
