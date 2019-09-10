template <typename OutputStream>
void
T <OutputStream>::put (char c)
{
	this -> output_stream . put
	(
		c ^ this -> masking_key [this -> masking_key_index]
	);

	this -> masking_key_index =
		(this -> masking_key_index + 1) % this -> masking_key . size ();
}
