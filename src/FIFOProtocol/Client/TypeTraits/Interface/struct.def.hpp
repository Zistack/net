template <typename Request, typename Response>
struct T
{
	template <typename OutputStream>
	void
	writeRequest (const Request & request, OutputStream && output_stream);

	template <typename InputStream>
	Response
	readResponse (InputStream && input_stream);
};
