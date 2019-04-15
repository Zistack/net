template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream) const
{
	if (this -> status_code != 1005)
	{
		IO::Rule::putIntType <decltype (this -> status_code)>
		(
			this -> status_code,
			std::forward <OutputStream> (output_stream)
		);

		if (this -> reason)
		{
			output_stream . print (this -> reason . stdString ());
		}
	}
}
