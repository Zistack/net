template <typename OutputStream>
void
T <OutputStream>::put (char c)
{
	this -> m_output_stream . put
	(
		c ^ this -> m_masking_key [this -> m_masking_key_index]
	);

	this -> m_masking_key_index =
		(this -> m_masking_key_index + 1) % this -> m_masking_key . size ();
}
