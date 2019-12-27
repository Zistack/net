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

		this -> m_headers = HeaderMap::T
		(
			std::forward <InputStream> (input_stream)
		);

		IO::Util::expect (std::forward <InputStream> (input_stream), "\r\n");
	}

	// No entity for information responses, regardless of headers.
	if (this -> m_status_code >= 100 && this -> m_status_code <= 199) return;

	// No entity for No Content, regardless of headers.
	if (this -> m_status_code == 204) return;

	// No entity for Not Modified, regardless of headers;
	if (this -> m_status_code == 304) return;

	auto entity_kit = Input::headersToEntity <false>
	(
		this -> m_headers,
		temp_file_threshhold
	);

	// It should actually be impossible for this to be false for a response.
	if (entity_kit)
	{
		TransferEncoding::Decoder::T decoder = entity_kit -> first;
		this -> m_entity = std::move (entity_kit -> second);

		decoder . decode
		(
			std::forward <InputStream> (input_stream),
			* this -> m_entity,
			input_slot
		);
	}

	this -> m_headers . remove ("Content-Length");
	this -> m_headers . remove ("Transfer-Encoding");
}

T::T
(
	const std::string & version,
	uint64_t status_code,
	const std::string & reason_phrase,
	const HeaderMap::T & headers,
	std::optional <Entity::T> && entity
)
:	m_version (version),
	m_status_code (status_code),
	m_reason_phrase (reason_phrase),
	m_headers (headers),
	m_entity (std::move (entity))
{
}
