template <typename Protocol, typename Dispatcher>
const Output::T <Protocol> &
T <Protocol, Dispatcher>::output () const
{
	return static_cast <Protocol &> (* this) . output ();
}

template <typename Protocol, typename Dispatcher>
Output::T <Protocol> &
T <Protocol, Dispatcher>::output ()
{
	return static_cast <Protocol &> (* this) . output ();
}
