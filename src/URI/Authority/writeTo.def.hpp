template <typename OutputStream>
void
T::writeTo (OutputStream && output_stream) const
{
	if (this -> user_info)
	{
		output_stream . print (Util::encode (* this -> user_info));
		output_stream . put ('@');
	}

	Host::writeTo (this -> host, std::forward <OutputStream> (output_stream));

	if (this -> port)
	{
		output_stream . put (':');
		output_stream . print (std::to_string (* this -> port));
	}
}
