template <typename InputStream>
char
T <InputStream>::peek ()
{
	return this -> m_input_stream . peek () ^
		this -> m_masking_key [this -> m_masking_key_index];
}
