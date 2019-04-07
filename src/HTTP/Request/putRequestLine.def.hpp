template <typename OutputStream>
void
T::putRequestLine (OutputStream && output_stream) const
{
	output_stream . print (this -> method);

	output_stream . put (' ');

	this -> uri . writeTo (std::forward <OutputStream> (output_stream));

	output_stream . put (' ');

	output_stream . print (this -> version);
	output_stream . print ("\r\n");
}
