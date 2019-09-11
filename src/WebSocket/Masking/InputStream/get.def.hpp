template <typename InputStream>
char
T <InputStream>::get ()
{
	char c =
		this -> m_input_stream . get () ^
		this -> m_masking_key [this -> m_masking_key_index];

	this -> m_masking_key_index =
		(this -> m_masking_key_index + 1) % this -> m_masking_key . size ();

	return c;
}
