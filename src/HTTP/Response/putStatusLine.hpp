template <typename OutputStream>
void
T::statusLineToString (OutputStream && output_stream) const
{
	output_stream . print (this -> version);

	output_stream . put (' ');

	output_stream . print (std::to_string (this -> status_code));

	output_stream . put (' ');

	output_stream . print (this -> reason_phrase);

	output_stream . print ("\r\n");
}