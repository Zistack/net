template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream) const
{
	output_stream.print (this->toString ());
}
