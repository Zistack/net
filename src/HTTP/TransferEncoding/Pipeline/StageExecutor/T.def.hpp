template <typename InputStream, typename Stage, typename OutputStream>
T <InputStream, Stage, OutputStream>::T
(
	InputStream input_stream,
	Stage & stage,
	OutputStream output_stream
)
:	m_input_stream (input_stream),
	m_stage (stage),
	m_output_stream (output_stream)
{
}
