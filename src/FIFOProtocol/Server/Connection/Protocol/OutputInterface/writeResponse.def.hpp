template <typename Interface, typename Protocol, typename Response>
template <typename OutputStream>
void
T <Interface, Protocol, Response>::writeResponse
(
	const Response & response,
	OutputStream && output_stream
)
{
	this -> interface () . writeResponse
	(
		response, std::forward <OutputStream> (output_stream)
	);
}
