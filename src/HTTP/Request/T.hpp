T::T (IO::Interface::InputStream::T & blocking_input_stream,
    IO::CancelSignal::T & input_cancel_signal,
    Failure::CancelScope::T & cancel_scope)
{
	const std::string message_prefix = "HTTP::Request::T::T\n";

	IO::PeekableInputStream::T input_stream (input_stream);

	try
	{
		{
			Failure::CancelScope::Bind::T input_cancel_binding (
			    cancel_scope, input_cancel_signal);

			this->getRequestLine (input_stream);

			this->headers = HeaderMap::T (input_stream);

			IO::Util::expect (input_stream, "\r\n");
		}

		// That number needs to be configurable.
		this->entity = headersToEntity<true> (this->headers, 4096);

		if (this->entity)
		{
			TransferEncoding::Decoder::T decoder;
			headersToDecoder (this->headers, decoder);

			decoder.decode (
			    input_stream, input_cancel_signal, *entity, cancel_scope);
		}

		this->headers.remove ("Content-Length");
		this->headers.remove ("Transfer-Encoding");
	}
	catch (Failure::Error::T & e)
	{
		throw e.set (message_prefix + e.what ());
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
