template <typename Request, typename Response, typename Details>
void
T <Request, Response, Details>::prime ()
{
	this -> input () . prime ();
	this -> Output::T <T, Response, Details>::output () . prime ();
}
