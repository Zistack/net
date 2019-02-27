T::T (IO::Interface::InputStream::T & blocking_input_stream,
    IO::CancelSignal::T & input_cancel_signal,
    Failure::CancelScope::T & cancel_scope,
    uint64_t temp_file_threshhold)
{
	IO::PeekableInputStream::T input_stream (blocking_input_stream);

	{
		Failure::CancelScope::Bind::T input_cancel_binding (
		    cancel_scope, input_cancel_signal);

		this->getStatusLine (input_stream);

		this->headers = HeaderMap::T (input_stream);

		IO::Util::expect (input_stream, "\r\n");
	}

	this->entity =
	    Util::headersToEntity<false> (this->headers, temp_file_threshhold);

	if (this->entity)
	{
		TransferEncoding::Decoder::T decoder;
		Util::headersToDecoder<false> (this->headers, decoder);

		decoder.decode (
		    input_stream, input_cancel_signal, *entity, cancel_scope);
	}

	this->headers.remove ("Content-Length");
	this->headers.remove ("Transfer-Encoding");
}

T::T (const std::string & version,
    uint64_t status_code,
    const std::string & reason_phrase,
    const HeaderMap::T & headers,
    std::unique_ptr<Entity::T> && entity) :
    version (version),
    status_code (status_code),
    reason_phrase (reason_phrase),
    headers (headers),
    entity (std::move (entity))
{
}
