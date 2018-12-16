void
T::writeTo (IO::Interface::OutputStream::T & output_stream) const
{
	for (const auto & [field_name, field_value] : this->map)
	{
		output_stream.print (field_name);
		output_stream.print (": ");
		output_stream.print (field_value);
		output_stream.print ("\r\n");
	}
}
