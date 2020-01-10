template <typename Interface>
template <typename ProxyInterface, typename>
void
T <Interface>::writeIdle ()
{
	this -> interface () . writeIdle ();
}
