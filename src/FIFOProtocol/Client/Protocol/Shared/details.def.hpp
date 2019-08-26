template <typename Protocol, typename Details>
Details &
T <Protocol, Details>::details ()
{
	return static_cast <Protocol &> (* this) . m_details;
}

template <typename Protocol, typename Details>
const Details &
T <Protocol, Details>::details () const
{
	return static_cast <Protocol &> (* this) . m_details;
}
