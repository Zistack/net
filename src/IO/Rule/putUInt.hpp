template <typename OutputStream>
void
putUInt (uint64_t uint, OutputStream && output_stream)
{
	output_stream.print (std::to_string (uint));
}
