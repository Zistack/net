template <typename Protocol, typename Response, typename Details>
const Details &
T <Protocol, Response, Details>::details () const
{
	return static_cast <Protocol &> (* this) . details ();
}

template <typename Protocol, typename Response, typename Details>
Details &
T <Protocol, Response, Details>::details ()
{
	return static_cast <Protocol &> (* this) . details ();
}
