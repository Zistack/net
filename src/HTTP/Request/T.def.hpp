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

			this -> headers = HeaderMap::T
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
			this -> headers,
			temp_file_threshhold
		);

		if (entity_kit)
		{
			TransferEncoding::Decoder::T decoder = entity_kit -> first;
			this -> entity = std::move (entity_kit -> second);

			decoder . decode
			(
				std::forward <InputStream> (input_stream),
				this -> entity,
				input_slot
			);
		}

		this->headers.remove ("Content-Length");
		this->headers.remove ("Transfer-Encoding");
	}
	catch (const Failure::ResourceError::T & e)
	{
		this->e_ptr = std::make_exception_ptr (CodeError::T (500, e.what ()));
	}
	catch (const Failure::EncodingError::T & e)
	{
		this->e_ptr = std::make_exception_ptr (CodeError::T (400, e.what ()));
	}
	catch (const Failure::SyntaxError::T & e)
	{
		this->e_ptr = std::make_exception_ptr (CodeError::T (400, e.what ()));
	}
	catch (const Failure::SemanticError::T & e)
	{
		this->e_ptr = std::make_exception_ptr (CodeError::T (400, e.what ()));
	}
	catch (const Failure::ImplementationError::T & e)
	{
		this->e_ptr = std::make_exception_ptr (CodeError::T (501, e.what ()));
	}
	catch (const Failure::Error::T & e)
	{
		this->e_ptr = std::make_exception_ptr (CodeError::T (500, e.what ()));
	}
}

T::T
(
	const std::string & method,
	const URI::T & uri,
	const std::string & version,
	const HeaderMap::T & headers,
	std::optional <Entity::T> && entity
)
:	method (method),
	uri (uri),
	version (version),
	headers (headers),
	entity (std::move (entity))
{
}
