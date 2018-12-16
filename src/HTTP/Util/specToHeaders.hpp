HeaderMap::T
specToHeaders (const Entity::T & entity,
    const NullableString::T & transfer_encoding_spec)
{
	HeaderMap::T headers;

	if (transfer_encoding_spec)
	{
		headers.insert ("Transfer-Encoding", transfer_encoding_spec);
	}
	else
	{
		headers.insert ("Content-Length", std::to_string (entity.size ()));
	}

	return headers;
}
