template <typename Interface, typename Response>
template <typename InputStream>
Response
T <Interface, Response>::readResponse (InputStream && input_stream)
{
	return this -> interface () . readResponse
	(
		std::forward <InputStream> (input_stream)
	);
}
