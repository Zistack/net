template
<
	typename Interface,
	typename Protocol,
	typename Request,
	typename Response
>
const Interface &
T <Interface, Protocol, Request, Response>::interface () const
{
	return static_cast <Interface &> (* this);
}

template
<
	typename Interface,
	typename Protocol,
	typename Request,
	typename Response
>
Interface &
T <Interface, Protocol, Request, Response>::interface ()
{
	return static_cast <Interface &> (* this);
}
