void
putHeader (IO::OutputStream::T * output_stream, Header::T header)
{
	output_stream -> print (header.first);
	output_stream -> print (": ");
	output_stream -> print (header.second);
}
