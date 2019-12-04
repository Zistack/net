template <typename Interface, typename Request, typename Response>
const T <Interface, Request, Response> &
T <Interface, Request, Response>::fifoProtocol () const
{
	return * this;
}

template <typename Interface, typename Request, typename Response>
T <Interface, Request, Response> &
T <Interface, Request, Response>::fifoProtocol ()
{
	return * this;
}
