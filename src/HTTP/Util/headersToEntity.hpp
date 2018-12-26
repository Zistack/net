template <bool is_request>
std::unique_ptr<Entity::T>
headersToEntity (const HeaderMap::T & headers, size_t temp_file_threshhold)
{
	if (headers.contains ("Transfer-Encoding"))
	{
		if (headers.contains ("Content-Length"))
		{
			throw Failure::SemanticError::T (
			    "Cannot specify both Transfer-Encoding and Content-Length "
			    "headers\n");
		}

		return std::make_unique<NonblockingEntity::T> (
		    std::make_unique<IO::TempFile::T> ());
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
				    std::make_unique<IO::String::T> ());
			}
			else
			{
				return std::make_unique<NonblockingEntity::T> (
				    std::make_unique<IO::TempFile::T> ());
			}
		}
		else if (is_request)
		{
			return nullptr;
		}
		else
		{
			return std::make_unique<NonblockingEntity::T> (
			    std::make_unique<IO::TempFile::T> ());
		}
	}
}
