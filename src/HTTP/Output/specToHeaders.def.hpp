HeaderMap::T
specToHeaders
(
	const Entity::T & entity,
	const TransferEncoding::Config::T & transfer_encoding_config
)
{
	HeaderMap::T headers;

	std::optional <std::string> transfer_encoding =
		transfer_encoding_config . getTransferEncoding ();

	if (transfer_encoding)
	{
		headers . insert ("Transfer-Encoding", * transfer_encoding);
	}
	else
	{
		headers . insert ("Content-Length", std::to_string (entity . size ()));
	}

	return headers;
}
