template <typename Interface, typename Protocol, typename Response>
void
T <Interface, Protocol, Response>::cancelProtocol ()
{
	this -> protocol () . cancel ();
}
