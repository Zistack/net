void
T::putStatusLine (IO::Interface::OutputStream::T & output_stream)
{
	output_stream . print (std::to_string (this -> status_code));

	output_stream . put (' ');

	this -> uri . writeTo (output_stream);

	output_stream . put (' ');

	output_stream . print (this -> version);

	output_stream . print ("\r\n");
}
