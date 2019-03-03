void
T::put (char c)
{
	this->output_stream.put (c ^ this->masking_key[i]);

	i = (i + 1) % 4;
}
