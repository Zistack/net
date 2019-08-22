template <typename Request, typename Response>
struct T
{
	template <typename InputStream>
	Request
	readRequest (InputStream && input_stream);

	Response
	map (const Request & request);

	template <typename OutputStream>
	void
	writeResponse (OutputStream && output_stream);
};
