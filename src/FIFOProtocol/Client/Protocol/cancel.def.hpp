template <typename Interface, typename Request, typename Response>
void
T <Interface, Request, Response>::cancel ()
{
	this -> input () . cancel ();
	this -> output () . cancel ();
}
