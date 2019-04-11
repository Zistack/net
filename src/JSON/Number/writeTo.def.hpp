template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream, size_t indentation) const
{
	IO::Util::indent (std::forward <OutputStream> (output_stream), indentation);
	output_stream . print (this -> base);
	if (mantissa) output_stream . print ("." + this -> mantissa . stdString ());
	if (exponent) output_stream . print ("E" + this -> exponent . stdString ());
}
