HeaderMap::T
specToHeaders (const Entity::T & entity,
    const TransferEncoding::Encoder::Config::T & transfer_encoding_config)
{
	HeaderMap::T headers;

	if (transfer_encoding_config.transfer_encoding)
	{
		headers.insert (
		    "Transfer-Encoding", transfer_encoding_config.transfer_encoding);
	}
	else
	{
		headers.insert ("Content-Length", std::to_string (entity.size ()));
	}

	return headers;
}
