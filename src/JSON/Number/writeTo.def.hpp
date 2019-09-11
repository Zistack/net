template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream, size_t indentation) const
{
	IO::Util::indent (std::forward <OutputStream> (output_stream), indentation);
	output_stream . print (this -> m_base);
	if (this -> m_mantissa)
	{
		output_stream . print ("." + this -> m_mantissa . stdString ());
	}
	if (this -> m_exponent)
	{
		output_stream . print ("E" + this -> m_exponent . stdString ());
	}
}
