template <typename SeedGenerator>
T::T (SeedGenerator && getSeed) : m_handle (newHandle ())
{
	uint32_t seed_size = kcapi_rng_seedsize (this -> m_handle . get ());

	uint8_t seed_buf [seed_size];

	// Some RNGs don't have a seed size because they seed themselves.
	if (seed_size) getSeed (seed_buf, seed_size);

	if (kcapi_rng_seed (this -> m_handle . get (), seed_buf, seed_size))
	{
		throw Failure::ResourceError::T ("Failed to seed RNG\n");
	}
}
