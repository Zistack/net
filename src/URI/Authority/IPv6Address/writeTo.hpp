template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream)
{
	output_stream.print (this->toString ());
}
