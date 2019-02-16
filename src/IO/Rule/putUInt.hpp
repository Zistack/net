void
putUInt (uint64_t uint, IO::Interface::OutputStream::T & output_stream)
{
	output_stream.print (std::to_string (uint));
}
