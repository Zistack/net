template <typename NonblockingInputStream>
T <NonblockingInputStream>::T (NonblockingInputStream input_stream)
:	input_stream (input_stream),
	begin (0),
	end (0),
	buffer (new char [T::BUFFER_SIZE]),
	eof_bit (false)
{
}
