template
<
	typename Protocol,
	typename Request,
	typename Response,
	typename Details
>
const Output::T <Protocol, Response, Details> &
T <Protocol, Request, Response, Details>::output () const
{
	return static_cast <Protocol &> (* this) .
		Output::template T <Protocol, Response, Details>::output ();
}

template
<
	typename Protocol,
	typename Request,
	typename Response,
	typename Details
>
Output::T <Protocol, Response, Details> &
T <Protocol, Request, Response, Details>::output ()
{
	return static_cast <Protocol &> (* this) .
		Output::template T <Protocol, Response, Details>::output ();
}
