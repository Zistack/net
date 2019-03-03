char
T::get ()
{
	char c = input_stream.get () ^ masking_key[i];

	i = (i + 1) % 4;

	return c;
}
