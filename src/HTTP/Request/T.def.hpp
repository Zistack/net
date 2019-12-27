template <typename InputStream, typename CancellableSlot>
T::T
(
	InputStream && input_stream,
	CancellableSlot & input_slot,
	uint64_t temp_file_threshhold
)
{
	try
	{
		{
			Scope::T header_scope (input_slot, input_stream);

			this -> getRequestLine (std::forward <InputStream> (input_stream));

			this -> m_headers = HeaderMap::T
			(
				std::forward <InputStream> (input_stream)
			);

			IO::Util::expect
			(
				std::forward <InputStream> (input_stream),
				"\r\n"
			);
		}

		auto entity_kit = Input::headersToEntity <true>
		(
			this -> m_headers,
			temp_file_threshhold
		);

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

		if (! this -> m_headers . contains ("Host"))
		{
			throw Failure::SemanticError::T ("Host is required\n");
		}

		std::string host_string = this -> m_headers . at ("Host");
		if (! host_string . empty ())
		{
			this -> m_host = Header::Host::T (host_string);
		}

		if
		(
			(this -> m_host && ! this -> m_host -> match (this -> m_uri)) ||
			(! this -> m_host && this -> m_uri . authority)
		)
		{
			throw Failure::SemanticError::T
			(
				"Host header field value must match host in request URI\n"
			);
		}

		this -> m_headers . remove ("Host");
	}
	catch (...)
	{
		this -> m_e_ptr = std::current_exception ();
	}
}

T::T
(
	const std::string & method,
	const URI::T & uri,
	const std::string & version,
	const std::optional <Header::Host::T> & host,
	const HeaderMap::T & headers,
	std::optional <Entity::T> && entity
)
:	m_method (method),
	m_uri (uri),
	m_version (version),
	m_host (host),
	m_headers (headers),
	m_entity (std::move (entity))
{
}
