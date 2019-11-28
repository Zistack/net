template
<
	typename Interface,
	typename Protocol,
	typename Request,
	typename Response
>
template <typename InputStream>
Request
T <Interface, Protocol, Request, Response>::readRequest
(
	InputStream && input_stream
)
{
	return this -> interface () . readRequest
	(
		std::forward <InputStream> (input_stream)
	);
}
