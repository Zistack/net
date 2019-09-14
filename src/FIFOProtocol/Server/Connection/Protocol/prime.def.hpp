template <typename Request, typename Response, typename Details>
void
T <Request, Response, Details>::prime ()
{
	this -> input () . prime ();
	this -> output () . prime ();
}
