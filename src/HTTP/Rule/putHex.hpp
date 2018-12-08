void
putHex (uint64_t num, IO::Interface::OutputStream::T & output_stream)
{
	std::string hex;

	for (; num; num >>= 4) hex.push_front (IO::nubbleToHex (num & 0x0F));

	output_stream.print (hex);
}
