template <typename Interface, typename Request, typename Response>
const T <Interface, Request, Response> &
T <Interface, Request, Response>::input () const
{
	return * this;
}

template <typename Interface, typename Request, typename Response>
T <Interface, Request, Response> &
T <Interface, Request, Response>::input ()
{
	return * this;
}
