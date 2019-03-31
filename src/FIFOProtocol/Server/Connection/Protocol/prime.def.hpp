template <typename Request, typename Response, typename Interface>
void
T <Request, Response, Interface>::prime ()
{
	this -> input . prime ();
	this -> output . prime ();
}
