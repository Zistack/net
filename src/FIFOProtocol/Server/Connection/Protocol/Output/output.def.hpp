template <typename Interface, typename Response>
const T <Interface, Response> &
T <Interface, Response>::output () const
{
	return * this;
}

template <typename Interface, typename Response>
T <Interface, Response> &
T <Interface, Response>::output ()
{
	return * this;
}
