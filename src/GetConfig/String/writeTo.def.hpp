template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream) const
{
	output_stream . put ('"');
	for (char c : this -> value)
	{
		if (c == '"')
		{
			output_stream . print ("\"");
		}
		else
		{
			output_stream . put (c);
		}
	}
	output_stream . put ('"');
}
