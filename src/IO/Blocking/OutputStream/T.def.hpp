template <typename NonblockingOutputStream>
T <NonblockingOutputStream>::T (NonblockingOutputStream output_stream)
:	output_stream (output_stream),
	next (0),
	buffer (new char [T::BUFFER_SIZE])
{
}
