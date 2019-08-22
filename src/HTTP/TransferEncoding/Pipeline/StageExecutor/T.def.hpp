template <typename InputStream, typename Stage, typename OutputStream>
T <InputStream, Stage, OutputStream, true>::T
(
	InputStream input_stream,
	Stage & stage,
	OutputStream output_stream,
	IO::Pipe::T && pipe
)
:	Implementation::T <InputStream, Stage, OutputStream>
	(
		std::forward <InputStream> (input_stream),
		stage,
		std::forward <OutputStream> (output_stream)
	),
	m_pipe (std::move (pipe))
{
}
