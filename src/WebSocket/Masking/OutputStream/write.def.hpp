template <typename OutputStream>
void
T <OutputStream>::write (const char * buffer, size_t count)
{
	unsigned int i;
	for (i = 0; i < count; ++i)
	{
		this -> output_stream . put (buffer [i]);
	}
}
