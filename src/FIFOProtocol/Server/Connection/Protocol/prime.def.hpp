template <typename Interface, typename Request, typename Response>
void
T <Interface, Request, Response>::prime ()
{
	this -> input () . prime ();
	this -> output () . prime ();
}
