template <typename Interface, typename Request, typename Response>
template <typename ProxyInterface, typename>
void
T <Interface, Request, Response>::writeIdle ()
{
	this -> interface () . writeIdle ();
}
