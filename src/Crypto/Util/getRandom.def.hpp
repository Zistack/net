size_t
getRandom (uint8_t * buffer, size_t count)
{
	ssize_t size = getrandom (buffer, count, 0);

	if (size < 0)
	{
		throw Failure::ResourceError::T
		(
			std::string ("getrandom: ") + strerror (errno) + "\n"
		);
	}

	return (size_t) size;
}
