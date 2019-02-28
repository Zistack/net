void
T::writeTo (Masking::OutputStream::T & output_stream)
{
	if (this -> status_code != 1005)
	{
		IO::Rule::putIntType <decltype (this -> status_code)> (this -> status_code, output_stream);

		if (this -> reason)
		{
			output_stream . print (this -> reason . stdString ());
		}
	}
}
