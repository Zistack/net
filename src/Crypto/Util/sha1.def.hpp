void
sha1 (const uint8_t * bytes, uint32_t count, uint8_t * hash)
{
	int32_t size = kcapi_md_sha1 (bytes, count, hash, SHA1_SIZE);

	if (size < 0)
	{
		throw Failure::ResourceError::T ("Failed to compute SHA1 hash\n");
	}
}
