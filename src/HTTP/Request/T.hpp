T::T (IO::Interface::InputStream::T & blocking_input_stream,
    IO::CancelSignal::T & input_cancel_signal,
    Failure::CancelScope::T & cancel_scope,
    uint64_t temp_file_threshhold)
{
	IO::PeekableInputStream::T input_stream (blocking_input_stream);

	try
	{
		{
			Failure::CancelScope::Bind::T input_cancel_binding (
			    cancel_scope, input_cancel_signal);

			this->getRequestLine (input_stream);

			this->headers = HeaderMap::T (input_stream);

			IO::Util::expect (input_stream, "\r\n");
		}

		this->entity =
		    Util::headersToEntity<true> (this->headers, temp_file_threshhold);

		if (this->entity)
		{
			TransferEncoding::Decoder::T decoder;
			Util::headersToDecoder<true> (this->headers, decoder);

			decoder.decode (
			    input_stream, input_cancel_signal, *entity, cancel_scope);
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

T::T (const std::string & method,
    const URI::T & uri,
    const std::string & version,
    const HeaderMap::T & headers,
    std::unique_ptr<Entity::T> && entity) :
    method (method),
    uri (uri),
    version (version),
    headers (headers),
    entity (std::move (entity))
{
}
