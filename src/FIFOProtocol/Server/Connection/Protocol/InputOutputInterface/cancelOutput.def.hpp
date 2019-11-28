template
<
	typename Interface,
	typename Protocol,
	typename Request,
	typename Response
>
void
T <Interface, Protocol, Request, Response>::cancelOutput ()
{
	this -> output () . cancel ();
}
