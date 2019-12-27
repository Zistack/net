template <bool is_request>
std::optional <std::pair <TransferEncoding::Decoder::T, Entity::T>>
headersToEntity (const HeaderMap::T & headers, size_t temp_file_threshhold)
{
	if (headers . contains ("Transfer-Encoding"))
	{
		if (headers . contains ("Content-Length"))
		{
			throw Failure::SemanticError::T
			(
				"Cannot specify both Transfer-Encoding and Content-Length "
				"headers\n"
			);
		}

		return std::make_pair
		(
			TransferEncoding::Decoder::T
			(
				headers . at ("Transfer-Encoding"),
				is_request
			),
			Entity::T ()
		);
	}
	else if (headers . contains ("Content-Length"))
	{
		Header::ContentLength::T content_length
		(
			headers . at ("Content-Length")
		);

		return std::make_pair
		(
			TransferEncoding::Decoder::T (content_length),
			Entity::T (content_length, temp_file_threshhold)
		);
	}
	else if constexpr (is_request)
	{
		return std::nullopt;
	}
	else
	{
		return std::make_pair
		(
			TransferEncoding::Decoder::T (),
			Entity::T ()
		);
	}
}
