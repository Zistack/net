template <typename InputStream, typename Stage, typename OutputStream>
T <InputStream, Stage, OutputStream>::T
(
	InputStream input_stream,
	Stage & stage,
	OutputStream output_stream
)
:	input_stream (input_stream), stage (stage), output_stream (output_stream)
{
}
