template
<
	typename Interface,
	typename Protocol,
	typename Request,
	typename Response
>
void
T <Interface, Protocol, Request, Response>::pushOutput
(
	const Thread::Delay::T <Response> & response_delay
)
{
	this -> output () . push (response_delay);
}
