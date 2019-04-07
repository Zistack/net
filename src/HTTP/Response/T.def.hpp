template <typename InputStream, typename CancellableSlot>
T::T
(
	InputStream && input_stream,
	CancellableSlot & input_slot,
	uint64_t temp_file_threshhold
)
{
	{
		Scope::T header_scope (input_slot, input_stream);

		this -> getStatusLine (std::forward <InputStream> (input_stream));

		this -> headers = HeaderMap::T
		(
			std::forward <InputStream> (input_stream)
		);

		IO::Util::expect (std::forward <InputStream> (input_stream), "\r\n");
	}

	auto entity_kit = Input::headersToEntity <false>
	(
		this -> headers,
		temp_file_threshhold
	);

	if (this -> entity)
	{
		TransferEncoding::Decoder::T decoder = entity_kit -> first;
		this -> entity = std::move (entity_kit -> second);

		decoder . decode
		(
			std::forward <InputStream> (input_stream),
			* entity,
			input_slot
		);
	}

	this -> headers . remove ("Content-Length");
	this -> headers . remove ("Transfer-Encoding");
}

T::T
(
	const std::string & version,
	uint64_t status_code,
	const std::string & reason_phrase,
	const HeaderMap::T & headers,
	std::optional <Entity::T> && entity
)
:	version (version),
	status_code (status_code),
	reason_phrase (reason_phrase),
	headers (headers),
	entity (std::move (entity))
{
}
