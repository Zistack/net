template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream)
{
	output_stream . print (this -> name);
	if (this -> version)
	{
		output_stream . put ('/');
		output_stream . print (* this -> version);
	}
}
