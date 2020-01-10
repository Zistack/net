template <typename Interface, typename Request, typename Response>
void
T <Interface, Request, Response>::pushInput
(
	const Thread::Delay::T <Response> & response_delay
)
{
	this -> input () . push (response_delay);
}
