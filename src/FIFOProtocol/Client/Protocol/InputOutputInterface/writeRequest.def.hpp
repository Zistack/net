template <typename Interface, typename Request, typename Response>
template <typename OutputStream>
void
T <Interface, Request, Response>::writeRequest
(
	const Request & request,
	OutputStream && output_stream
)
{
	this -> interface () . writeRequest
	(
		request,
		std::forward <OutputStream> (output_stream)
	);
}
