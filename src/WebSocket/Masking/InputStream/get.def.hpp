template <typename InputStream>
char
T <InputStream>::get ()
{
	char c =
		this -> input_stream . get () ^
		this -> masking_key [this -> masking_key_index];

	this -> masking_key_index = (this -> masking_key_index + 1) % 4;

	return c;
}
