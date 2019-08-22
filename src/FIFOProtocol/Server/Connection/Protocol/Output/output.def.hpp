template <typename Protocol, typename Response, typename Details>
const T <Protocol, Response, Details> &
T <Protocol, Response, Details>::output () const
{
	return * this;
}

template <typename Protocol, typename Response, typename Details>
T <Protocol, Response, Details> &
T <Protocol, Response, Details>::output ()
{
	return * this;
}
