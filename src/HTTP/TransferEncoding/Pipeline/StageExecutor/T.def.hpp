template <typename InputStream, typename Stage, typename OutputStream>
T <InputStream, Stage, OutputStream>::T
(
	InputStream input_stream,
	const Stage & stage,
	OutputStream output_stream
)
:	m_input_stream (std::forward <InputStream> (input_stream)),
	m_stage (stage),
	m_output_stream (std::forward <OutputStream> (output_stream))
{
}
