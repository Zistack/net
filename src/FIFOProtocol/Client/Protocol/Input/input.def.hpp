template <typename Interface, typename Response>
const T <Interface, Response> &
T <Interface, Response>::input () const
{
	return * this;
}

template <typename Interface, typename Response>
T <Interface, Response> &
T <Interface, Response>::input ()
{
	return * this;
}
