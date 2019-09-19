template <typename Request, typename Response, typename Details>
void
T <Request, Response, Details>::cancel ()
{
	this -> input () . cancel ();
	this -> Output::T <T, Response, Details>::output () . cancel ();
}
