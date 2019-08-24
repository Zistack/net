struct kcapi_handle *
T::newHandle ()
{
	struct kcapi_handle * handle;

	if (kcapi_rng_init (& handle, "stdrng", 0))
	{
		throw Failure::ResourceError::T ("Failed to create RNG\n");
	}

	return handle;
}
