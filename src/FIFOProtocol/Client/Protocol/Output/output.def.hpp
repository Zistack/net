template <typename Interface, typename Request>
const T <Interface, Request> &
T <Interface, Request>::output () const
{
	return * this;
}

template <typename Interface, typename Request>
T <Interface, Request> &
T <Interface, Request>::output ()
{
	return * this;
}
