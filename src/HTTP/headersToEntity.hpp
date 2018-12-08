template <bool is_request>
std::unique_ptr<Entity::T>
headersToEntity (const HeaderMap & transfer_encoding_spec,
    size_t temp_file_threshhold)
{
	if (headers.contains ("Transfer-Encoding"))
	{
		if (headers.contains ("Content-Length"))
		{
			// Bad shit.
		}

		return std::make_unique<NonblockingEntity::T> (
		    {new IO::TempFile::T ()});
	}
	else
	{
		if (headers.contains ("Content-Length"))
		{
			Header::ContentLength::T content_length (
			    headers.at ("Content-Length"));

			if (content_length < temp_file_threshhold)
			{
				return std::make_unique<BlockingEntity::T> (
				    {new IO::String::T ()});
			}
			else
			{
				return std::make_unique<NonblockingEntity::T> (
				    {new IO::TempFile::T ()});
			}
		}
		else if (is_request)
		{
			return nullptr;
		}
		else
		{
			return std::make_unique<NonblockingEntity::T> (
			    {new IO::TempFile::T ()});
		}
	}
}
