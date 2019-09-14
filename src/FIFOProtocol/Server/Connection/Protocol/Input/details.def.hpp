template
<
	typename Protocol,
	typename Request,
	typename Response,
	typename Details
>
const Details &
T <Protocol, Request, Response, Details>::details () const
{
	return static_cast <Protocol &> (* this) . m_details;
}

template
<
	typename Protocol,
	typename Request,
	typename Response,
	typename Details
>
Details &
T <Protocol, Request, Response, Details>::details ()
{
	return static_cast <Protocol &> (* this) . m_details;
}
