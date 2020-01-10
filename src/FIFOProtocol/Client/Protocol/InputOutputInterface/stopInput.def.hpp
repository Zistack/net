template <typename Interface, typename Request, typename Response>
void
T <Interface, Request, Response>::stopInput ()
{
	this -> input () . stop ();
}
