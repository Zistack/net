template <typename Protocol, typename Request, typename Details>
const T <Protocol, Request, Details> &
T <Protocol, Request, Details>::output () const
{
	return * this;
}

template <typename Protocol, typename Request, typename Details>
T <Protocol, Request, Details> &
T <Protocol, Request, Details>::output ()
{
	return * this;
}
