template <typename Protocol, typename Dispatcher>
const T <Protocol, Dispatcher> &
T <Protocol, Dispatcher>::input () const
{
	return * this;
}

template <typename Protocol, typename Dispatcher>
T <Protocol, Dispatcher> &
T <Protocol, Dispatcher>::input ()
{
	return * this;
}
