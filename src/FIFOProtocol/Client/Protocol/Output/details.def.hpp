template <typename Protocol, typename Request, typename Details>
const Details &
T <Protocol, Request, Details>::details () const
{
	return static_cast <Protocol &> (* this) -> details ();
}

template <typename Protocol, typename Request, typename Details>
Details &
T <Protocol, Request, Details>::details ()
{
	return static_cast <Protocol &> (* this) -> details ();
}
