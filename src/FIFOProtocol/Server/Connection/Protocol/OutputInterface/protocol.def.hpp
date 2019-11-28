template <typename Interface, typename Protocol, typename Response>
const Protocol &
T <Interface, Protocol, Response>::protocol () const
{
	return static_cast <Protocol &> (* this);
}

template <typename Interface, typename Protocol, typename Response>
Protocol &
T <Interface, Protocol, Response>::protocol ()
{
	return static_cast <Protocol &> (* this);
}
