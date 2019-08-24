uint32_t
T::generate (uint8_t * buffer, uint32_t count)
{
	int32_t size = kcapi_rng_generate
	(
		this -> m_handle . get (),
		buffer,
		count
	);

	if (size < 0)
	{
		throw Failure::ResourceError::T ("Failed to generate random data\n");
	}

	return (uint32_t) size;
}
