void
putHeaders (IO::Interface::OutputStream::T <char> * output_stream, Headers::T * headers)
{
	for (Header::T header : * headers)
	{
		putHeader (output_stream, header);

		output_stream -> print ("\r\n");
	}
}
