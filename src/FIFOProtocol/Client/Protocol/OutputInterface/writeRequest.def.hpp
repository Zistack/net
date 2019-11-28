template <typename Interface, typename Request>
template <typename OutputStream>
void
T <Interface, Request>::writeRequest
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
