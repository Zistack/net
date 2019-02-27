HeaderMap::T
specToHeaders (const Entity::T & entity,
    const TransferEncoding::Encoder::Config::Value::T &
        transfer_encoding_config)
{
	HeaderMap::T headers;

	NullableString::T transfer_encoding =
	    transfer_encoding_config.getTransferEncoding ();

	if (transfer_encoding)
	{
		headers.insert ("Transfer-Encoding", transfer_encoding.stdString ());
	}
	else
	{
		headers.insert ("Content-Length", std::to_string (entity.size ()));
	}

	return headers;
}
