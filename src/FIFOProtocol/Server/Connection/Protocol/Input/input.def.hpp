template
<
	typename Protocol,
	typename Request,
	typename Response,
	typename Details
>
const T <Protocol, Request, Response, Details> &
T <Protocol, Request, Response, Details>::input () const
{
	return * this;
}

template
<
	typename Protocol,
	typename Request,
	typename Response,
	typename Details
>
T <Protocol, Request, Response, Details> &
T <Protocol, Request, Response, Details>::input ()
{
	return * this;
}
